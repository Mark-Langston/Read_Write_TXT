// CSC252 Programming in C++
// Mark Langston    6/8/2024

#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Program intro
    std::cout << "CSC252 - Reading and Writing Text Files" << std::endl;

    std::string inputFilePath;
    std::string outputFilePath;

    // Prompts user for file path of text file
    std::cout << "Enter the path of the input file: ";
    std::getline(std::cin, inputFilePath);

    std::ifstream inputFile(inputFilePath);

    // Prompts user for where to save the text file
    std::cout << "Enter the path for the output file: ";
    std::getline(std::cin, outputFilePath);

    std::ofstream outputFile(outputFilePath);

    std::string line;

    // Loops through each line of the inputFile
    while (std::getline(inputFile, line)) {
        if (!line.empty()) {
            outputFile << line << std::endl;
        }
    }

    // Closes the files
    inputFile.close();
    outputFile.close();

    // Function that displays the files contents
    auto displayFileContent = [](const std::string& fileName) {
        std::ifstream file(fileName);
        std::string line;
        std::cout << fileName << ":" << std::endl;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        std::cout << "-------------------" << std::endl;
        };

    // Display contents of input and output files
    displayFileContent(inputFilePath);
    displayFileContent(outputFilePath);

    return 0;
}