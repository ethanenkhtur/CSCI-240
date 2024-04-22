//CSCI 240 daily - Reverse Number

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N, quotient, remainder;
    
    cout << "N value (must be positive)? ";
    cin >> N;

    while (N <= 0) {
        cout << "Error: the N-value must be positive. Try again: ";
        cin >> N;
    }

    quotient = N;

    cout << endl <<  "Original: " << N << endl;
    cout << "Reversed: ";

    while (quotient != 0) {
        remainder = quotient % 10;
        cout << remainder;
        quotient = quotient / 10;
    }

    cout << endl;

    return 0;
  }