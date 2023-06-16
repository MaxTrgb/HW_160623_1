/*Given a text file. Calculate the length of the shortest word in this file 
(a word is a group of consecutive characters other than spaces and punctuation marks).*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    ifstream read;
    read.open("Task4.txt"); // Open the input file named "Task4.txt"

    if (!read.is_open()) {

        cout << "Error" << endl; // Display an error message if the file couldn't be opened
        return 1; // Return from the program with an error code
    }

    char element;
    int counter = 0;
    int min_word = INT_MAX; // Initialize the minimum word length to the maximum possible value

    while (read.get(element)) { // Read characters from the file until the end

        if (element != '\n' && element != ',' && element != '.' && element != ' ') {

            // If the character is not a newline, comma, dot, or space, it belongs to a word
            counter++; // Increment the word length counter
        }
        else {

            // If a word boundary is reached (newline, comma, dot, or space)
            if (counter < min_word && counter > 0) {

                // If the current word length is shorter than the minimum word length so far (excluding empty words)
                min_word = counter; // Update the minimum word length
            }

            counter = 0; // Reset the word length counter for the next word
        }
    }

    cout << min_word << endl; // Print the length of the shortest word in the file

    return 0;
}
