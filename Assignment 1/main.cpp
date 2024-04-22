/***************************************************************
CSCI 240        Program 1        Spring 2024
Name: Ethan Enkhtur
Section: 0001
Date Due: 01/26/24
Purpose: The purpose of this program is to calculate and display
the gravitational force between two objects.
The user provides the mass of the two objects and the
distance between the objects.
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "****************************************\n" << "    Gravitational Force Calculator\n" << "****************************************\n" << endl;
    
    float mass1, mass2, distance, gravitational_force;
    const float GRAVITATIONAL_CONSTANT = 0.667e-10;
    
    cout << "Enter the mass of object 1 (in kilograms): ";
    cin >> mass1;
    
    cout << "Enter the mass of object 2 (in kilograms): ";
    cin >> mass2;
    
    cout << "Enter the distance between the 2 objects (in meters): ";
    cin >> distance;
    
    gravitational_force = (mass1 * mass2 * GRAVITATIONAL_CONSTANT) / (distance * distance);
    
    cout << "\n\nThe force of gravitational attraction is: " << gravitational_force << " newtons." << endl;
    
    return 0;
}
