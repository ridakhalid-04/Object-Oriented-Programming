// File Handling - Task 1: Create, Write, Read and Append a file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // 1. Create notes.txt and write three lines
    ofstream outFile("notes.txt");
    if (!outFile) {
        cout << "Error: could not create notes.txt" << endl;
        return 1;
    }
    outFile << "This is the first line." << endl;
    outFile << "This is the second line." << endl;
    outFile << "This is the third line." << endl;
    outFile.close();
    cout << "notes.txt created and three lines written.\n";

    // 2. Read and display the contents
    ifstream inFile("notes.txt");
    string line;
    cout << "\n--- Contents of notes.txt ---\n";
    while (getline(inFile, line))
        cout << line << endl;
    inFile.close();

    // 3. Append name and roll number (ios::app keeps old content)
    string name, rollNo;
    cout << "\nEnter your name: ";
    getline(cin, name);
    cout << "Enter your roll number: ";
    getline(cin, rollNo);

    ofstream appendFile("notes.txt", ios::app);
    appendFile << "Name: " << name << endl;
    appendFile << "Roll No: " << rollNo << endl;
    appendFile.close();

    // Show the final file
    ifstream finalFile("notes.txt");
    cout << "\n--- Contents after appending ---\n";
    while (getline(finalFile, line))
        cout << line << endl;
    finalFile.close();

    return 0;
}