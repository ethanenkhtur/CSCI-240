#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double itemPrice, totalCost;
    int itemCount;
    
    cout << "What is the price for a single item? ";
    cin >> itemPrice;
    
    cout << "How many items were purchased? ";
    cin >> itemCount;
    
    totalCost = itemPrice * itemCount;
    
    cout << endl << setw(5) << itemCount << " items at $" << fixed <<           setprecision(2) << itemPrice << " each will cost $" << totalCost << endl;
    
    return 0;
}
