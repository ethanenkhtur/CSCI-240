/***************************************************************
CSCI 240        Program 2        Spring 2024
Name: Ethan Enkhtur
Section: 0001
Date Due: 02/02/24
Purpose: The purpose of this program is to calculate and display the X and Y-coordinates for the vertex of a parabola.
the user is asked to enter values, calculations are performed, and the results of the calculations are displayed.
***************************************************************/


#include <iostream>
#include <iomanip>

using namespace std;

const int LABEL_SPACE = 20;
const int VALUE_SPACE = 11;

int main() {
    int a, b, c;
    float valueX, valueY;

    cout << "Enter the a coefficient: ";
    cin >> a;

    cout << "Enter the b coefficient: ";
    cin >> b;

    cout << "Enter the c coefficient: ";
    cin >> c;

    // Calculations for the X and Y values of vertex are completed using the coefficients provided by the user.
    valueX = (-1.0 * b) / (2 * a);
    valueY = (a * valueX * valueX) + (b * valueX) + c;

    // Output's head is formatted.
    cout << "\n\n-------------------------------" << "\n  Quadratic Equation Analyzer" << "\n-------------------------------" << endl;

    // The coefficient's labels and values are formatted in the output.
    cout << left << setw(LABEL_SPACE) << "a Coefficient" << right << setw(VALUE_SPACE) << a << endl << left << setw(LABEL_SPACE) << "b Coefficient" << right << setw(VALUE_SPACE) << b << endl << left << setw(LABEL_SPACE) << "c Coefficient" << right << setw(VALUE_SPACE) << c << endl;

    cout << "-------------------------------" << endl;

    // The vertex's labels and values are formatted in the output.
    cout << "Vertex" << endl << left << setw(LABEL_SPACE) << "X Coordinate" << left << setw(LABEL_SPACE) << right << setw(VALUE_SPACE) << fixed << setprecision(4) << valueX << endl << left << setw(LABEL_SPACE) << "Y Coordinate" << left << setw(LABEL_SPACE) << right << setw(VALUE_SPACE) << valueY << endl;

    return 0;
}