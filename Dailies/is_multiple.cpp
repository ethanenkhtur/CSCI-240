//Is Multiple main

#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    int num1, num2;
    
    //get two integer numbers
    cout << "What is the first number? ";
    cin >> num1;
    
    cout << "What is the second number? ";
    cin >> num2;

    cout << endl;
    
    if (num1 > 0 && num2 > 0) {
        if (num1 % num2 == 0)
            cout << num1 << " is a multiple of " << num2 << endl;
        else
            cout << num1 << " is NOT a multiple of " << num2 << endl;
    } else
        cout << "*** Invalid input: one or both values is not positive" << endl; 

    return 0;

} // end main() 