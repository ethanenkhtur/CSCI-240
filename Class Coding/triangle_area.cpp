/*********************************************************
Write a COMPLETE C++ program that will calculate and
display the area of a triangle.

The user should be prompted for the base and height of the
triangle.

Use the following formula to calculate the area of a triangle:

Triangle area = 1/2 * base * height



The results (**AFTER** the prompts for base and
height) should be similar to:

*************************
Area Calculator

Base:      XXXXX.XX
Height:    YYYY.YYY

Area:      ZZZ.ZZ
*************************


*********************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    //step 1: create variables
    float base_value, height_value, tri_area;
  
    //step 2: get values for base and height of triangle
    cout << "Enter the base of the triangle: ";
    cin >> base_value;
  
    cout << "What is the height of the triangle? ";
    cin >> height_value;
  
  
    //step 3: calculate area of triangle
    tri_area = 1/2 * base_value * height_value;
  
    //step 4: display table of results
  
    return 0;
}
  
  
