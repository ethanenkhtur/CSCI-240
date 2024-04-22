/***************************************************************
CSCI 240        Program 7        Spring 2024
Name: Ethan Enkhtur
Section: 0001
Date Due: 03/29/24
Purpose: The purpose of this program is processing two sets of data into arrays before displaying various statistics on the arrays.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int buildArray( string filename, double array[] );
void printArray( string title, double array[], int numValues );
void sortArray( double array[], int numValues );
double mean( double array[], int numValues );
double median( double array[], int numValues );
double low( double array[], int numValues );
double high( double array[], int numValues );
double standardDeviation( double array[], int numValues );
void printStatistics(string title, double array[], int numValues);

const int MAX_ARRAY_SIZE = 20;
const float END_OF_DATA = -999.99;
const int MAX_PER_LINE = 8;

int main() {
    double arr1[MAX_ARRAY_SIZE], arr2[MAX_ARRAY_SIZE];
    int numValues1, numValues2;
    
    // Building two arrays consisting of data from text files
    numValues1 = buildArray("data7A.txt", arr1);
    numValues2 = buildArray("data7B.txt", arr2);


    // Printing unsorted arrays
    printArray("Unsorted Set A", arr1, numValues1);
    cout << endl << endl;
    printArray("Unsorted Set B", arr2, numValues2);
    cout << endl << endl;


    sortArray(arr1, numValues1);
    sortArray(arr2, numValues2);

    // Printing sorted arrays
    printArray("Sorted Set A", arr1, numValues1);
    cout << endl << endl;
    printArray("Sorted Set B", arr2, numValues2);
    cout << endl << endl;


    cout << endl << endl;
    printStatistics("Set A Statistics", arr1, numValues1);
    cout << endl << endl;
    printStatistics("Set B Statistics", arr2, numValues2);


    // Differences Display
    cout << endl << endl;
    cout << "Differences" << endl << endl;
    cout << left << setw(20) << "Mean:" << right << setw(12) << abs(mean(arr1, numValues1) - mean(arr2, numValues2)) << endl;
    cout << left << setw(20) << "Median:" << right << setw(12) << abs(median(arr1, numValues1) - median(arr2, numValues2)) << endl;
    cout << left << setw(20) << "Standard Deviation:" << right << setw(12) << abs(standardDeviation(arr1, numValues1) - standardDeviation(arr2, numValues2)) << endl;
}

// Name: buildArray
// Use of function: Pools data from a file containing numbers to add each of them into an array.
// Arguments:   string fileName: the name of the input file
//              double array[]: array to which data would be added
// Value returned: the number of values in the constructed array
int buildArray(string fileName, double array[]) {
    double incomingValues;
    int numValuesRead = 0;

    ifstream infile;
    infile.open(fileName);

    if (infile.fail()) {
        cout << "input file did not open" << endl;
        exit(-1);
    }

    while (infile and numValuesRead < MAX_ARRAY_SIZE) {
        infile >> incomingValues;
        if (incomingValues == -999.99)
            break;
        
        array[numValuesRead] = incomingValues;
        numValuesRead++;
    }

    infile.close();

    return numValuesRead;

}

// Name: printArray
// Use of function: displays the data of a given array
// Arguments:   string title: a title that is given before åll the data is displayed
//              double array[]: array of which the data would be printed
//              int numValues: number of values in the provided array
// Value returned: none
void printArray(string title, double array[], int numValues) {
    cout << title << endl << endl;

    for (int i = 0; i < numValues; i++) {
        cout << setw(8) << fixed << setprecision(2) << array[i] << " ";

        if ((i + 1) % MAX_PER_LINE == 0 and i != 0)
            cout << endl;
    }
}

// Name: sortArray
// Use of function: sorts the data of a given array in an ascending numerical order
// Arguments:   double array[]: array that would be sorted
//              int numValues: number of values in the provided array
// Value returned: none
void sortArray(double array[], int numValues) {
    double lowestSoFar;
    int replacementIndex, minIndex; 
    
    // Selection Sort Algorithm
    for (int i = 0; i < numValues; i++) {
        lowestSoFar = array[i];

        for (minIndex = i; minIndex < numValues; minIndex++)
            if (array[minIndex] <= lowestSoFar) {
                lowestSoFar = array[minIndex];
                replacementIndex = minIndex;
            }
        
        array[replacementIndex] = array[i];
        array[i] = lowestSoFar;
    }
}

// Name: mean
// Use of function: computes the mean of the numbers in the provided array
// Arguments:   double array[]: array that contains the elements that will be used for calculating the mean
//              int numValues: number of values in the provided array
// Value returned: mean value from all the values in the provided array
double mean(double array[], int numValues) {
    double sum = 0;

    for (int i = 0; i < numValues; i++) {
        sum += array[i];
    }

    return sum / numValues;
}

// Name: median
// Use of function: computes the median of the numbers in the provided array
// Arguments:   double array[]: array that contains the elements that will be used for calculating the median
//              int numValues: number of values in the provided array
// Value returned: median value from all the values in the provided array
double median(double array[], int numValues) {
    double median;

    sortArray(array, numValues);

    if (numValues % 2 == 0) {
        median = (array[(numValues / 2) - 1] + array[numValues / 2]) / 2.0;
    } else {
        median = array[numValues / 2];
    }

    return median;
}

// Name: low
// Use of function: ƒinds the lowest number in the provided array
// Arguments:   double array[]: array that contains the elements that will be used for finding the lowest.
//              int numValues: number of values in the provided array
// Value returned: lowest value from all the values in the provided array
double low(double array[], int numValues) {
    sortArray(array, numValues);
    
    return array[0];
}

// Name: high
// Use of function: ƒinds the highest number in the provided array
// Arguments:   double array[]: array that contains the elements that will be used for finding the highest.
//              int numValues: number of values in the provided array
// Value returned: highest value from all the values in the provided array
double high(double array[], int numValues) {
    sortArray(array, numValues);

    return array[numValues - 1];
}

// Name: standardDeviation
// Use of function: computes the standard deviation in the provided array
// Arguments:   double array[]: array that contains the elements that will be used for calculating the standard deviation.
//              int numValues: number of values in the provided array
// Value returned: standart deviation fo all the values in the provided array
double standardDeviation(double array[], int numValues) {
    double sumOfValues = 0, sumOfSquared = 0;

    sortArray(array, numValues);

    for (int i = 0; i < numValues; i++) {
        sumOfValues += array[i];
        sumOfSquared += array[i] * array[i];
    }

    return sqrt((sumOfSquared - (sumOfValues * sumOfValues / numValues)) / (numValues - 1));
}

// Name: printStatistics
// Use of function: displays the statistics of a given array
// Arguments:   string title: a title that is given before all the data is displayed
//              double array[]: array of which the data would be printed
//              int numValues: number of values in the provided array
// Value returned: none
void printStatistics(string title, double array[], int numValues) {
    cout << title << endl << endl;


    cout << left << setw(20) << "Mean:" << right << setw(12) << mean(array, numValues) << left << setw(11) << "    Median:" << right << setw(12) << median(array, numValues) << endl;

    cout << left << setw(20) << "Low:" << right << setw(12) << low(array, numValues) << left << setw(11) << "    High:" << right << setw(12) << high(array, numValues) << endl;
    
    cout << left << setw(20) << "Standard Deviation:" << right << setw(12) << standardDeviation(array, numValues) << endl;
}
