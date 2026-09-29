// File Handling - Task 3: Copy content from notes.txt to another file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream source("notes.txt");
    if (!source) {
        cout << "Error: notes.txt not found. Run Task 1 first." << endl;
        return 1;
    }
    ofstream destination("copy.txt");

    string line;
    int count = 0;
    while (getline(source, line)) {
        destination << line << endl;
        count++;
    }
    source.close();
    destination.close();

    cout << "Content copied from notes.txt to copy.txt" << endl;
    cout << "Total number of lines copied: " << count << endl;

    // Display the copied file to verify
    ifstream check("copy.txt");
    cout << "\n--- Contents of copy.txt ---\n";
    while (getline(check, line))
        cout << line << endl;
    check.close();

    return 0;
}