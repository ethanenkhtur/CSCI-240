/***************************************************************
CSCI 240        Program 4        Spring 2024
Name: Ethan Enkhtur
Section: 0001
Date Due: 02/23/24
Purpose: The purpose of this program is generating three sets of random numbers.
***************************************************************/


#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Declarations of constants
const int FOR_SIZE = 45;
const int MAX_WHILE_SIZE_RANDOM = 75;
const int MAX_DO_WHILE_RANDOM_SIZE = 50;
const double MIN_DOUBLE_VALUE = 0.0;
const double MAX_DOUBLE_VALUE = 300.0;
const int VALUES_IN_ONE_LINE = 7;


int main() {
    int range, i = 1, countOdd = 0, countEven = 0, countGreater = 0, width = 13;

    // the random generator initialization
    srand(33);

    cout << "Set 1 has exactly 45 values" << endl;

    // generating random values for Set 1
    for (i = 1; i <= FOR_SIZE; i++) {
        // the actual generation of the values for the setf
        int random = rand();

        // displaying with a format
        cout << right << setw(width) << random;

        // counting the odd values in the set
        if (random % 2 == 1) {
            countOdd++;
        }

        // starting at a new line after 7 values in one line
        if (i % VALUES_IN_ONE_LINE == 0)
            cout << endl;
    }

    cout << endl << endl << "There are " << countOdd << " odd numbers in Set 1" << endl;

    // determining the size of Set 2
    range = rand() % MAX_WHILE_SIZE_RANDOM + 1;
    
    cout << endl << endl << "Set 2 has exactly " << range << " values" << endl;

    i = 1;

    // generating the random values in Set 2
    while (i <= range) {
        // the actual generation of the values for the set
        int random = rand();

        // displaying with a format
        cout << right << setw(width) << random;

        // counting the even values in the set
        if (random % 2 == 0) {
            countEven++;
        }

        // starting at a new line after 7 values in one line
        if (i % VALUES_IN_ONE_LINE == 0)
            cout << endl;
        i++;
    }

    cout << endl << endl << "There are " << countEven << " even numbers in Set 2" << endl;

    // determining the size of Set 3
    range = rand() % MAX_DO_WHILE_RANDOM_SIZE + 1;
    
    cout << endl << endl << "Set 3 has exactly " << range << " values" << endl;

    i = 1;

    // generating the values for Set 3
    do {
        // the actual generation of the values for the set
        double random = MIN_DOUBLE_VALUE + (rand() / (RAND_MAX / (MAX_DOUBLE_VALUE - MIN_DOUBLE_VALUE)));

        // displaying with a format
        cout << right << setw(width) << fixed << setprecision(1) << random;

        // counting the values greater than 200.0 in the set
        if (random >= 200.0) {
            countGreater++;
        }

        // starting at a new line after 7 values in one line
        if (i % VALUES_IN_ONE_LINE == 0)
            cout << endl;
        
        i++;
    } while (i <= range);

    cout << endl << endl << "There are " << countGreater << " numbers greater than 200.0 in Set 3" << endl;

    return 0;
}