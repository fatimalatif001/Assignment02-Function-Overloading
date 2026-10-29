// Answer 1: printInfo(string, int) runs because there is no (string, char) function. So char 'B' gets converted to its ASCII value 66.
// Answer 2: C++ does not allow overloading based only on return type. Both functions would have the same parameter list.
// Answer 3: printInfo(string, int) and printInfo(int, string).

#include <iostream>
#include <string>
using namespace std;

void printInfo(string name) {
    cout << "Name: " << name << endl;
}

void printInfo(string name, int rollNo) {
    cout << "Name: " << name << " | Roll No: " << rollNo << endl;
}

void printInfo(int rollNo, string name) {
    cout << "Roll No: " << rollNo << " | Name: " << name << endl;
}

void printInfo(string name, double cgpa) {
    cout << "Name: " << name << " | CGPA: " << cgpa << endl;
}

void printInfo(char grade) {
    cout << "Grade: " << grade << endl;
}

int main() {
    printInfo("Ali");
    printInfo("Ali", 12);
    printInfo(12, "Ali");
    printInfo("Ali", 3.5);
    printInfo('A');
    printInfo("Sara", 'B');
    return 0;
}
