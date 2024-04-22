/***************************************************************
CSCI 240        Program 5        Spring 2024
Name: Ethan Enkhtur
Section: 0001
Date Due: 03/01/24
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

char getMenuChoice();
int getRequiredValue(string prompt);

int main() {
    int num1, num2, result;
    char menu_choice;

    menu_choice = getMenuChoice();

    // loop that executes until the user decides to quit
    while (menu_choice != 'q' and menu_choice != 'Q') {
        //processing - determine which option was selected from the menu
        switch (menu_choice) {
            // displaying the result of an addition of two integer numbers
            case '+':
                num1 = getRequiredValue("What is the first number to add? ");
                num2 = getRequiredValue("What is the first number to add? ");

                result = num1 + num2;

                cout << endl << num1 << " + " << num2 << " = " << result << endl << endl;

                break;
            // displaying the result of a subtraction between two values
            case '-':
                num1 = getRequiredValue("What is the first number to subtract? ");
                num2 = getRequiredValue("What is the second number to substract? ");

                result = num1 - num2;

                cout << endl << num1 << " - " << num2 << " = " << result << endl << endl;

                break;
            // displaying the result of a multiplication of two numbers
            case '*':
                num1 = getRequiredValue("What is the first number to multiply? ");
                num2 = getRequiredValue("What is the second number to multiply? ");

                result = num1 * num2;

                cout << endl << num1 << " * " << num2 << " = " << result << endl << endl;

                break;
            // displaying the quotient and remainder of two integer numbers
            case '/':
                num1 = getRequiredValue("What is the dividend? ");
                num2 = getRequiredValue("What is the divisor? ");

                result = num1 / num2;
                int remainder;
                remainder = num1 % num2;

                cout << endl << num1 << " / " << num2 << " = " << result << endl;
                cout << num1 << " % " << num2 << " = " << remainder << endl << endl;

                break;
            // displaying the result of a number to another number's power
            case '^':
                num1 = getRequiredValue("What is the base number? ");
                num2 = getRequiredValue("What is the power? ");

                result = 1;
                for (int i = 1; i <= num2; i++)
                    result *= num1;

                cout << endl << num1 << "^" << num2 << " = " << result << endl << endl;

                break;
            // displaying the result of a number's factorial
            case '!':
                num1 = getRequiredValue("What is the number? ");

                result = 1;
                for (int i = 1; i <= num1; i++)
                    result *= i;

                cout << endl << num1 << "!" << " = " << result << endl << endl;

                break;
            // informing of invalid options from the menu to the user in so cases
            default:
                cout << endl << "This is an invalid operation!" << endl << endl;

        }

        // prompting a menu selction from the user
        menu_choice = getMenuChoice();
    }

    return 0;
}

// function that asks the user to select an option from the menu options
char getMenuChoice() {
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

    return menu_choice;
}

// function that obtains the required values needed for code blocks in each cases
int getRequiredValue(string prompt) {
    int value;

    cout << endl << prompt;
    cin >> value;

    return value;
}