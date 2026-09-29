// File Handling - Task 2: Count the number of lines in notes.txt
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("notes.txt");
    if (!inFile) {
        cout << "Error: notes.txt not found. Run Task 1 first." << endl;
        return 1;
    }

    string line;
    int count = 0;
    while (getline(inFile, line))
        count++;
    inFile.close();

    cout << "Total number of lines in notes.txt: " << count << endl;
    return 0;
}