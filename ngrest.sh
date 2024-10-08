#!/usr/bin/env bash

set -eu

TO_INSTALL=
TO_INSTALL_OPT=

# detect OS
OS=
case $(uname -s) in
  MSYS*|MINGW*)
    OS=MSYS
    export PATH="/mingw64/bin:$PATH"
    ;;
  Linux)
    OS=Linux
    ;;
  Darwin)
    OS=Darwin
    ;;
  *)
    echo "This OS is not supported: $(uname -s)" >&2
    exit 1
esac

for app in git make cmake g++
do
  $app --version >/dev/null 2>&1 || TO_INSTALL+="$app "
done

if [ $OS = Linux ]
then
  inotifywait --help >/dev/null 2>&1 || ERR=$?
  if [ $ERR == 127 ] # command not found
  then
    TO_INSTALL_OPT+="inotify-tools "
  fi
fi

[ $OS = MSYS ] && SUDO= || SUDO=sudo

if [ -n "$TO_INSTALL" ]
then
  pkg=

  # detect package manager
  for p in apt-get yum port brew pacman
  do
    if which $p >/dev/null 2>&1
    then
      pkg=$p
      break
    fi
  done

  if [ -z "$pkg" ]
  then
    echo "Cannot detect package manager"
    exit 1
  fi

  case $pkg in
  brew|port)
    YES=
    INSTALL=install
    [ $pkg != brew ] || SUDO=
    ;;
  pacman)
    YES=--noconfirm
    INSTALL=-S
    TO_INSTALL=${TO_INSTALL//g++/mingw-w64-$(uname -m)-gcc}
    ;;
  *)
    YES=-y
    INSTALL=install
    ;;
  esac

  if [ -n "$SUDO" ]
  then
    echo "This script will install missing dependencies for you: $TO_INSTALL$TO_INSTALL_OPT..."
    echo "To continue please enter your password, or press Ctrl+C to install it manually."
  fi
  $SUDO $pkg $INSTALL $YES $TO_INSTALL </dev/null
  [ -n "$TO_INSTALL_OPT" ] || $SUDO $pkg $INSTALL $YES $TO_INSTALL_OPT </dev/null || true
  [ $pkg != brew ] || SUDO=sudo
fi

if [ $OS = MSYS ]
then
  export NGREST_HOME=$APPDATA/ngrest
else
  export NGREST_HOME=$HOME/.ngrest
fi

mkdir -p "$NGREST_HOME"
cd "$NGREST_HOME"

SRC_DIR=$NGREST_HOME/ngrest
BUILD_DIR=$SRC_DIR-build

rm -rf "$BUILD_DIR"

if [ -z "${UPGRADE:-}" ]
then
  test ! -e "$SRC_DIR" || mv "$SRC_DIR" "$SRC_DIR~$(date +%Y%m%d-%H%M%S)"
  git clone https://github.com/loentar/ngrest.git
fi

mkdir "$BUILD_DIR"
cd "$BUILD_DIR"

rm -f .build_ok
echo "Configuring ngrest for the build..."
if [ $OS = MSYS ]
then
  # supress platform warnings
  touch /usr/share/cmake-$(cmake --version | sed '1{s/cmake version //;q}')/Modules/Platform/$(uname -s).cmake 2>/dev/null || true
  cmake ${CMAKE_FLAGS:-} -GUnix\ Makefiles -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc ../ngrest >cmake-build.log
else
  cmake ${CMAKE_FLAGS:-} ../ngrest >cmake-build.log
fi

echo "Building ngrest. It may take few minutes..."
make >make-build.log
touch .build_ok
echo "Build OK"

if [ $OS = MSYS ]
then
  mkdir -p "$APPDATA/ngrest/bin/"
  cp -f "$SRC_DIR/scripts/ngrest" "$SRC_DIR/scripts/ngrest.cmd" "$APPDATA/ngrest/bin/"
  cp -f "$SRC_DIR/scripts/ngrest" /usr/bin/  # to be accessible from msys terminal
else
  # install to ~/bin if user already created it
  if [[ $PATH =~ ~/bin ]]
  then
    USERINST=1
  fi

  if [ -z "${USERINST:-}" ]
  then
    #ln -nsf $BUILD_DIR/deploy ngrest
    echo "Installing ngrest script into /usr/local/bin/"
    sudo cp -f $SRC_DIR/scripts/ngrest /usr/local/bin/
    sudo chown 0:0 /usr/local/bin/ngrest
    sudo chmod 755 /usr/local/bin/ngrest
  else
    echo "Installing ngrest script into ~/bin/"
    if [[ ! $PATH =~ ~/bin ]]
    then
      cat << EOF
 *** Please note: You must re-login after installation completed. Else 'ngrest' command may not work ***
If you cannot access 'ngrest' command after re-login you need to add this line into your startup scripts: ~/.bashrc or ~/.profile

  PATH="$HOME/bin:$PATH"

EOF
    fi

    mkdir -p ~/bin
    cp -f $SRC_DIR/scripts/ngrest ~/bin/
    chmod 755 ~/bin/ngrest
  fi
fi

if [ -z "${UPGRADE:-}" ]
then
  cat << EOF
Installation completed.

Now you can create your first project by typing:

  ngrest create myproject

EOF
else
  echo "Upgrade completed."
  killall -HUP ngrest
fi