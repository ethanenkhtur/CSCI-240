/***************************************************************
CSCI 240        Program 3        Spring 2024
Name: Ethan Enkhtur
Section: 0001
Date Due: 02/09/24
Purpose: The purpose of this program is to calculate and display the X and Y-coordinates for the vertex of a parabola. It also determines (and displays) the concavity of the parabola, and if the parabola has real roots and what they are if they exist.
The user is asked to enter values, calculations are performed, and the results of the calculations are displayed. 
***************************************************************/


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int LABEL_SPACE = 20;
const int VALUE_SPACE = 20;

int main() {
    int a, b, c;
    float valueX, valueY, discriminant, root1, root2;

    cout << "Enter the a coefficient (non-zero value): ";
    cin >> a;

    // Makes sure that the input is valid the first time.
    if (a == 0) {
        cout << "Error: the a-coefficient MUST be non-zero. Try again: ";
        cin >> a;
    }

    cout << "Enter the b coefficient: ";
    cin >> b;

    cout << "Enter the c coefficient: ";
    cin >> c;

    // Calculations for the X and Y values of vertex are completed using the coefficients provided by the user.
    valueX = (-1.0 * b) / (2 * a);
    valueY = (a * valueX * valueX) + (b * valueX) + c;

    // Output's head is formatted.
    cout << "\n\n----------------------------------------" << "\n  Quadratic Equation Analyzer" << "\n----------------------------------------" << endl;

    // The coefficient's labels and values are formatted in the output.
    cout << left << setw(LABEL_SPACE) << "a Coefficient" << right << setw(VALUE_SPACE) << a << endl << left << setw(LABEL_SPACE) << "b Coefficient" << right << setw(VALUE_SPACE) << b << endl << left << setw(LABEL_SPACE) << "c Coefficient" << right << setw(VALUE_SPACE) << c << endl;

    cout << "----------------------------------------" << endl;

    // The vertex's labels and values are formatted in the output.
    cout << "Vertex" << endl << left << setw(LABEL_SPACE) << "X Coordinate" << left << setw(LABEL_SPACE) << right << setw(VALUE_SPACE) << fixed << setprecision(3) << valueX << endl << left << setw(LABEL_SPACE) << "Y Coordinate" << left << setw(LABEL_SPACE) << right << setw(VALUE_SPACE) << valueY << endl;
    
    cout << "----------------------------------------" << endl;

    // Determines if the parabola of the given function opens up or down.
    if (a > 0) {
        cout << "The parabola opens UPWARD" << endl;
    } else {
        cout << "The parabola opens DOWNWARD" << endl;
    }

    cout << "----------------------------------------" << endl;

    // Determines discriminant
    discriminant = b * b - 4.0 * a * c;

    // Determines if there are roots and finds the value of roots if there are using fitting formulas.
    if (discriminant > 0) {
        cout << "The parabola has TWO roots" << endl;

        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);

        cout << left << setw(LABEL_SPACE) << "Root 1 - X Coordinate" << left << setw(LABEL_SPACE) << right << setw(VALUE_SPACE) << fixed << setprecision(3) << root1 << endl << left << setw(LABEL_SPACE) << "Root 2 - X Coordinate" << left << setw(LABEL_SPACE) << right << setw(VALUE_SPACE) << root2 << endl;

    } else if (discriminant == 0) {
        cout << "The parabola has ONE root" << endl;

        root1 = (-b + sqrt(discriminant)) / (2 * a);

        cout << left << setw(LABEL_SPACE) << "Root 1 - X Coordinate" << left << setw(LABEL_SPACE) << right << setw(VALUE_SPACE) << fixed << setprecision(3) << root1 << endl;

    } else {
        cout << "The parabola has NO roots" << endl;
    }

    return 0;
}