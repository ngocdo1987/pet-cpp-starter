#include <iostream>
#include <string>
 
using namespace std;
 
string& str_replace(const string &search, const string &replace, string &subject);
 
int main(int argc, char *argv[])
{
    string str;
 
    //test basic replace
    str    ="I have a lovely bunch of cocoa nuts";
    cout << str << endl;
    cout << str_replace(" ", " ;", str) << endl;
 
    //test removal of spaces
    str    ="I have a lovely bunch of cocoa nuts";
    cout << str << endl;
    cout << str_replace(" ", "", str) << endl;
 
    //this test will generate an infinite loop if not done in 1 pass
    str    ="I have a lovely bunch of cocoa nuts";
    cout << str << endl;
    cout << str_replace(" ", " a", str) << endl;
 
    return 0;
}
 
string& str_replace(const string &search, const string &replace, string &subject)
{
    string buffer;
 
    int sealeng = search.length();
    int strleng = subject.length();
 
    if (sealeng == 0)
        return subject;//no change
 
    for (int i = 0, j = 0; i < strleng; j = 0)
    {
        while (i + j <strleng && j < sealeng && subject[i+j] == search[j])
            j++;
        if (j == sealeng)//found 'search'
        {
            buffer.append(replace);
            i += sealeng;
        }
        else
        {
            buffer.append( &subject[i++], 1);
        }
    }
    subject = buffer;
    return subject;
}