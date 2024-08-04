#include <iostream>   // Including the input/output stream library
#include <fstream>    // Including the file stream library
#include <string>     // Including the string handling library
#include <vector>     // Including the vector container

// Function to display the content of a file
void displayFileContent(const std::string & filename) {
    std::ifstream file(filename); // Open file with given filename for reading
    std::string line; // Declare a string to store each line of text

    if (file.is_open()) { // Check if the file was successfully opened
        std::cout << "File content:" << std::endl; // Displaying a message indicating file content
        while (std::getline(file, line)) { // Read each line from the file
            std::cout << line << std::endl; // Display each line of the file
        }
        file.close(); // Close the file
    } else {
        std::cout << "Failed to open the file." << std::endl; // Display an error message if file opening failed
    }
}

    int main() {
    std::vector<std::string> inputFiles = { // List of input files
        "test1.txt",
        "test2.txt",
        "test3.txt",
        "test4.txt"
    };
    std::cout << "Content of test1.txt, test2.txt, test3.txt, text4.txt: " << std::endl;

    displayFileContent("test1.txt"); // Display content of "test1.txt"
    displayFileContent("test2.txt"); // Display content of "test2.txt"
    displayFileContent("test3.txt"); // Display content of "test3.txt"
    displayFileContent("test4.txt"); // Display content of "test4.txt"

    std::string outputFile = "merged_test_file.txt"; // Output file

    std::ofstream mergedFile(outputFile); // Create or overwrite the output file named "merged_test_file.txt" for writing

    if (mergedFile.is_open()) { // Check if the output file was successfully opened
        for (const auto & inputFile: inputFiles) { // Iterate through each input file
            std::ifstream inputFileStream(inputFile); // Open each input file for reading

            if (inputFileStream.is_open()) { // Check if the input file was successfully opened
                std::string line; // Declare a string to store each line of text

                while (std::getline(inputFileStream, line)) { // Read each line from the input file
                    mergedFile << line << "\n"; // Write each line to the merged file
                }

                inputFileStream.close(); // Close the input file
            } else {
                std::cout << "Failed to open input file: " << inputFile << std::endl; // Display an error message if file opening failed
            }
        }

        mergedFile.close(); // Close the merged file
        std::cout << "\nFiles merged successfully." << std::endl; // Display a success message
        std::cout << "\nContent of the merged file:" << std::endl;
        displayFileContent("merged_test_file.txt"); // Display content of "merged_test_file.txt"
    } else {
        std::cout << "Failed to open the output file." << std::endl; // Display an error message if output file opening failed
    }

    return 0; // Return 0 to indicate successful execution
}
