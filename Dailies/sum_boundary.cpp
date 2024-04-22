
/*
Sum Values Between Boundary Daily
*/

#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    int lower, upper, newLower, newUpper, sum = 0;

    //Get the lower and upper bounds
    cout << "What is the lower bound? ";
    cin >> lower;

    cout << "What is the upper bound? ";
    cin >> upper;

    if (lower > upper) {
        newLower = upper;
        newUpper = lower;
        lower = newLower;
        upper = newUpper;

        cout << endl << "*** boundary values have been swapped ***" << endl;
    }

    for (int i = lower; i <= upper; i++) {
        sum += i;
    }

    cout << endl << "The sum of the values between " << lower << " and " << upper << " is " << sum << endl;

    return 0;
}
