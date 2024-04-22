// 240 Count Factorial Digits Daily

#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    int N, result = 1, digits = 0, quotient;

    //Get the value for N
    cout << "N value (must be greater than or equal to 0)? ";
    cin >> N;

    if (N < 0 || N > 12) {
        cout << endl << "Invalid Input: " << N << endl;
    } else {
        for (int i = 1; i <= N; i++)
            result *= i;
        
        quotient = result;
        while (quotient != 0) {
            digits++;
            quotient /= 10;
        }

        cout << endl << N << "! is equal to " << result << ". There are " << digits << " digits." << endl;
    }

    return 0;
} // end main() 
