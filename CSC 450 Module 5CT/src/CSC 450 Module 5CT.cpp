//============================================================================
// Name        : CSC 450 Module 5CT.cpp
// Author      : Zach Winterton
// Date        : 01/21/2024
// Description : This C++ program prompts the user to enter a string, writes the string to a file, reads the content from that file, duplicates it into another file,
// and finally, reverses each line of the content in a third file. The program utilizes file stream operations and string manipulation.
//============================================================================

// Include necessary header files
#include <iostream>
#include <fstream>
using namespace std;

// Main function, entry point of program
int main() {
	// String variable to store user input
	string input;
	// Declaring output file stream
	ofstream outFile;
	// Open file and append to existing content of file
	outFile.open("CSC450_CT5_mod5.txt", ios::app);

	// Check if file is opened
	if (outFile.is_open()) {
		// Prompt user to enter a string
		cout << "Enter a string to be stored in the file: ";
		// Read line of input from user and store it in "input"
		getline(cin, input);
		// Write input string to opened file
		outFile << input << endl;
		// Close file
		outFile.close();
	}
	else {
		// If file cannot be opened, display error message
		cout << "Error opening file" << endl;
	}

	// Declare input & output file stream for reading and writing on files
	ifstream inFile;
	ofstream outFile2;
	// Open file "CSC450_CT5_mod5.txt" for reading and "CSC450_mod5-2.txt" for writing
	inFile.open("CSC450_CT5_mod5.txt");
	outFile2.open("CSC450_mod5-2.txt");

	// Check if both files are opened
	if (inFile.is_open() && outFile2.is_open()) {
		// Declare a string variable to store each line of input
		string line;
		// While loop that will read each line from input file and write it to output file
		while (getline(inFile, line)) {
		outFile2 << line << endl;
		}
		// Close input and output files
		inFile.close();
		outFile2.close();
	}
	else {
		// If either of files cannot be opened, display error message
		cout << "Error opening files" << endl;
	}

	// Declare variable for string reversal
	string reverse;
	// Declare input & output file stream for reading and writing reversed strings
	ifstream inFile2;
	ofstream outFile3;
	// Open file "CSC450_mod5-2.txt" for reading and "CSC450_mod5-reverse.txt" for writing
	inFile2.open("CSC450_mod5-2.txt");
	outFile3.open("CSC450_mod5-reverse.txt");

	// Check if both files are successfully opened
	if (inFile2.is_open() && outFile3.is_open()) {
		// Declare string variable to store each line of input
		string line;
		// Read each line from the input file, reverse them, and write the reversed strings to the output file
		while (getline(inFile2, line)) {
			reverse = string(line.rbegin(), line.rend());
			outFile3 << reverse << endl;
		}
		// Close input & output files
		inFile2.close();
		outFile3.close();
	}
	else {
		// If either of files cannot be opened, display error message
		cout << "Error opening file" << endl;
	}
	// Return to zero to indicate successful program execution
	return 0;
}

