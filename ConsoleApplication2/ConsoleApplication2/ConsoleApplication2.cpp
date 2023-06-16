/*Create a text file that contains positive, negative, zero numbers and arbitrary characters. 
Determine the number of positive, negative, zero numbers and words in each line of the file. 
Write the received values with appropriate comments in another text file.*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

// Function to count the number of positive, negative, and zero numbers in a line
void countNumbers(const string& line, int& positiveCount, int& negativeCount, int& zeroCount) {

    istringstream iss(line);
    string word;
    while (iss >> word) {

        // Remove commas from the word
        word.erase(remove(word.begin(), word.end(), ','), word.end());

        bool isNumber = true;

        // Check if the word is a number
        int decimalCount = 0;  // Count of decimal points
        for (char ch : word) {

            if (!isdigit(ch) && ch != '-' && ch != '.') {

                isNumber = false;
                break;
            }
            if (ch == '.') {

                decimalCount++;
            }
        }

        if (isNumber && decimalCount <= 1) {

            double number = stod(word);

            if (number > 0) {

                positiveCount++;
            }
            else if (number < 0) {

                negativeCount++;
            }
            else {
                zeroCount++;
            }
        }
    }
}

// Function to count the number of words in a line
int countWords(const string& line) {

    istringstream iss(line);
    string word;
    int wordCount = 0;

    while (iss >> word) {

        bool isWord = false;
        for (int i = 0; i < word.length(); i++) {

            if (isalpha(word[i])) {

                isWord = true;
                break;
            }
        }
        if (isWord) {

            wordCount++;
        }
    }
    return wordCount;
}

// Function to display the contents of a file
void displayFileContents(const string& filename) {

    ifstream file(filename);
    if (file) {

        string line;
        while (getline(file, line)) {

            cout << line << endl;
        }
        file.close();
    }
    else {

        cout << "Failed to open the file." << endl;
    }
}

int main() {
    ofstream inputFile("input.txt"); // File to store the input data

    // Check if the input file was successfully opened
    if (!inputFile) {

        cout << "Failed to open the input file." << endl;
        return 1;
    }

    string line;
    cout << "Enter the data (press Enter on an empty line to finish):\n";
    while (getline(cin, line) && !line.empty()) {

        inputFile << line << endl; // Write the line to the input file
    }

    // Close the input file
    inputFile.close();

    cout << "Input file created. You can find it in the current directory with the name input.txt." << endl;

    ifstream read("input.txt"); // Open the input file for reading

    if (!read.is_open()) {

        cout << "Failed to open the input file." << endl;
        return 1;
    }

    ofstream outputFile("results.txt"); // File to store the results and commentaries

    // Check if the output file was successfully opened
    if (!outputFile) {

        cout << "Failed to open the output file." << endl;
        return 1;
    }

    while (getline(read, line)) {

        int positiveCount = 0;
        int negativeCount = 0;
        int zeroCount = 0;

        // Count the number of positive, negative, and zero numbers in the line
        countNumbers(line, positiveCount, negativeCount, zeroCount);

        // Count the number of words in the line
        int wordCount = countWords(line);

        // Write results with appropriate comments to the output file
        outputFile << "Line: " << line << endl;
        outputFile << "Positive numbers: " << positiveCount << endl;
        outputFile << "Negative numbers: " << negativeCount << endl;
        outputFile << "Zero numbers: " << zeroCount << endl;
        outputFile << "Word count: " << wordCount << endl;
        outputFile << "------------------------------" << endl;
    }

    // Close the input and output files
    read.close();
    outputFile.close();

    cout << "Counting completed. Results and commentaries are written to results.txt." << endl;

    // Prompt the user to view the results file
    char choice;
    cout << "Do you want to view the results file? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y') {

        cout << "Contents of results.txt:\n";
        displayFileContents("results.txt");
    }

    return 0;
}
