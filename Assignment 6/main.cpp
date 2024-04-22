/***************************************************************
CSCI 240        Program 6        Spring 2024
Name: Ethan Enkhtur
Section: 0001
Date Due: 03/08/24
Purpose: The purpose of this program is performing the following arithmetic operations:
    • add two integer values
    • subtract two integer values
    • multiply two integer values
    • divide two integer values
    • raise an integer value to an integer power
    • calculate the factorial of an integer
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int addition(int, int);
int subtraction(int, int);
int multiplication(int, int);
int quotient(int, int);
int remainder(int, int);
int power(int, int);
int factorial(int);
int getValue(string prompt);
int getNonNegativeValue(string);
int getNonZeroValue(string);
char menu();

int main() {
    int num1, num2, output;
    char menu_choice;

    menu_choice = menu();

    // loop that executes until the user decides to quit
    while (menu_choice != 'q' and menu_choice != 'Q') {
        //processing - determine which option was selected from the menu
        switch (menu_choice) {
            // displaying the output of an addition of two integer numbers
            case '+':
                num1 = getValue("What is the first number to add? ");
                num2 = getValue("What is the first number to add? ");

                output = addition(num1, num2);

                cout << endl << num1 << " + " << num2 << " = " << output << endl << endl;

                break;
            // displaying the output of a subtraction between two values
            case '-':
                num1 = getValue("What is the first number to subtract? ");
                num2 = getValue("What is the second number to substract? ");

                output = subtraction(num1, num2);

                cout << endl << num1 << " - " << num2 << " = " << output << endl << endl;

                break;
            // displaying the output of a multiplication of two numbers
            case '*':
                num1 = getValue("What is the first number to multiply? ");
                num2 = getValue("What is the second number to multiply? ");

                output = multiplication(num1, num2);

                cout << endl << num1 << " * " << num2 << " = " << output << endl << endl;

                break;
            // displaying the quotient and remainder of two integer numbers
            case '/':
                num1 = getValue("What is the dividend? ");
                num2 = getNonZeroValue("What is the divisor? ");

                output = quotient(num1, num2);
                int remainderOutput;
                remainderOutput = remainder(num1, num2);

                cout << endl << num1 << " / " << num2 << " = " << output << endl;
                cout << num1 << " % " << num2 << " = " << remainderOutput << endl << endl;

                break;
            // displaying the output of a number to another number's power
            case '^':
                num1 = getValue("What is the base number? ");
                num2 = getNonNegativeValue("What is the power? ");

                output = power(num1, num2);

                cout << endl << num1 << "^" << num2 << " = " << output << endl << endl;

                break;
            // displaying the output of a number's factorial
            case '!':
                num1 = getNonNegativeValue("What is the number? ");

                output = factorial(num1);

                cout << endl << num1 << "!" << " = " << output << endl << endl;

                break;
            // informing of invalid options from the menu to the user in so cases
        }

        // prompting a menu selction from the user
        menu_choice = menu();
    }

    return 0;
}

// Name: menu
// Use of function: asks the user to select an option from the menu options and checks for validity of the input before returning the selected option
// Arguments: none
// Value returned: the character/operation the user picked
char menu() {
    char menu_choice;

    cout << endl << "What operation would you like to perform:" << endl
        << "  + addition" << endl
        << "  - subtraction" << endl
        << "  * multiplication" << endl 
	    << "  / division"<< endl
        << "  ^ number to power" << endl
        << "  ! factorial" << endl
        << "  q quit" << endl << endl
        << "Operation? ";
    cin >> menu_choice;

    while (menu_choice != '+' and menu_choice != '-' and menu_choice != '*' and menu_choice != '/' and menu_choice != '!' and menu_choice != '^' and menu_choice != 'q' and menu_choice != 'Q') {
        cout << "Error: that is an invalid operation. Try again: ";
        cin >> menu_choice;
    }

    return menu_choice;
}

// Name: getValue
// Use of function: asks the user to provide any integer value
// Arguments: string prompt: the prompt for which the user comes up with value
// Value returned: integer value user picked
int getValue(string prompt) {
    int value;

    cout << endl << prompt;
    cin >> value;

    return value;
}

// Name: addition
// Use of function: adds two integer numbers
// Arguments:   int num1: an integer value
//              int num2: another integer value
// Value returned: sum of two integer numbers
int addition(int num1, int num2) {
    return num1 + num2;
}

// Name: subtraction
// Use of function: subtracts two integer numbers
// Arguments:   int num1: an integer value
//              int num2: another integer value
// Value returned: subtraction of two integer numbers
int subtraction(int num1, int num2) {
    return num1 - num2;
}

// Name: multiplication
// Use of function: multiplies two integer values
// Arguments:   int num1: an integer value
//              int num2: another integer value
// Value returned: multiplication of two integer numbers
int multiplication(int num1, int num2) {
    return num1 * num2;
}

// Name: quotient
// Use of function: computes division of one integer value by another
// Arguments:   int num1: an integer value
//              int num2: another integer value
// Value returned: quotient of when num1 is divided num2
int quotient(int num1, int num2) {
    return num1 / num2;
}

// Name: remainder
// Use of function: computes remainder when one integer value is divided by another
// Arguments:   int num1: an integer value
//              int num2: another integer value
// Value returned: remainder of when num1 is divided by num2
int remainder(int num1, int num2) {
    return num1 % num2;
}

// Name: power
// Use of function: applies power to an integer value
// Arguments:   int base: an integer value that is the base
//              int power: another integer value that is the power
// Value returned: result of applying power to a base
int power(int base, int power) {
    int result = 1;

    for (int i = 1; i <= power; i++)
        result *= base;

    return result;
}

// Name: factorial
// Use of function: computes factorial of an integer value
// Arguments:   int num: an integer value
// Value returned: factorial of an integer number
int factorial(int num) {
    int result = 1;

    for (int i = 1; i <= num; i++)
        result *= i;

    return result;
}

// Name: getNonNegativeValue
// Use of function: asks the user to provide a non negative integer value while checking for validity
// Arguments: string prompt: the prompt for which the user comes up with value
// Value returned: a non-negative integer value
int getNonNegativeValue(string prompt) {
    int value;

    cout << endl << prompt;
    cin >> value;

    while (value < 0) {
        cout << "Error: the value cannot be negative. Try again: ";
        cin >> value;
    }

    return value;
}

// Name: menu()
// Use of function: asks the user to provide a non zero integer value while checking for validity
// Arguments: string prompt: the prompt for which the user comes up with value
// Value returned: a non-zero integer value
int getNonZeroValue(string prompt) {
    int value;

    cout << endl << prompt;
    cin >> value;

    while (value == 0) {
        cout << "Error: the value cannot be zero. Try again: ";
        cin >> value;
    }

    return value;
}