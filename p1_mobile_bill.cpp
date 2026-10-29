// Answer 1: In blank (c), sms must be specified as 0 because default arguments in C++ can only be omitted from right to left. Since data is provided, sms cannot be skipped.
// Answer 2: The call mobileBill(60, , 1.5) produces a syntax error because C++ does not allow empty parameter slots or skipping middle arguments.

#include <iostream>
using namespace std;

double mobileBill(int minutes, int sms = 0, double data = 0.0);
void printLine(char ch = '-', int n = 30);

int main() {
    printLine();
    cout << "Bill 1: " << mobileBill(100) << endl;
    cout << "Bill 2: " << mobileBill(100, 50) << endl;
    cout << "Bill 3: " << mobileBill(100, 50, 2.5) << endl;
    printLine('*', 10);
    cout << "Bill 4: " << mobileBill(60, 0, 1.5) << endl;
    printLine('=');
    return 0;
}

double mobileBill(int minutes, int sms, double data) {
    return (minutes * 2) + (sms * 1) + (data * 150);
}

void printLine(char ch, int n) {
    for (int i = 0; i < n; i++) cout << ch;
    cout << endl;
}
