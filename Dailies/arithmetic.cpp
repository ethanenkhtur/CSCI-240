//
//Arithmetic Daily
//

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int num1, num2;

    cout << "First number? ";
    cin >> num1;

    cout << "Second number? ";
    cin >> num2;

    cout << endl << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
    cout << num1 << " % " << num2 << " = " << num1 % num2 << endl;
    cout << endl << num2 << " - " << num1 << " = " << num2 - num1 << endl;
    cout << num2 << " / " << num1 << " = " << num2 / num1 << endl;
    cout << num2 << " % " << num1 << " = " << num2 % num1 << endl << endl;

    return 0;
  }