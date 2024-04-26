/***************************************************************
CSCI 240         Program 9     Spring 2024

Name: Ethan Enkhtur

Section: 0001

Due Date: 04/26/24

Purpose: Implement a class called PiggyBank that will be used to represent a collection of coins. Functionality will be added to the class.
***************************************************************/


#include <iostream>
#include <iomanip>

using namespace std;

//*************** Place the class description after this line ***************

class PiggyBank {
    private:
        int numPennies, numNickels, numDimes, numQuarters;

    public: 
        PiggyBank();
        PiggyBank(int, int, int, int);
        PiggyBank(const PiggyBank &otherBank);

        void printBank();
        void printBankValue();
        void print(string);

        void emptyTheBank();

        PiggyBank addBanks(int, int, int, int);
        PiggyBank addBanks(PiggyBank);
        
        void addCoins(int, int, int, int);
        void addNickels(int);
        void addPennies(int);
        void addDimes(int);
        void addQuarters(int);

        double calcBankValue();

        bool isEqual(int, int, int, int);
        bool isEqual(PiggyBank otherBank);

        bool isLessThan(int, int, int, int);
        bool isLessThan(PiggyBank otherBank);

        int getCoin(int coinIndex);

};

void printSectionTitle(string);


//****************************************************************************

int main() {
    PiggyBank firstBank = PiggyBank(12, 34, 56, 78);
    PiggyBank secondBank = PiggyBank(23, -5, -10, 31);
    PiggyBank thirdBank = PiggyBank(firstBank);


    printSectionTitle("Initial values in the bank objects");


    firstBank.print("Bank1 object");
    secondBank.print("Bank2 object");
    thirdBank.print("Bank3 object");

    
    printSectionTitle("Using the addBanks method with 4 arguments");


    PiggyBank fourthBank = PiggyBank();
    fourthBank.print("initial bank4 value");

    fourthBank = secondBank.addBanks(4, 27, 45, 7);

    secondBank.print("bank2 values after using addBanks method");
    fourthBank.print("bank4 values after using addBanks method");

    
    printSectionTitle("Using the addBanks method with PiggyBank object");


    PiggyBank fifthBank = PiggyBank();

    firstBank.print("initial bank1 value");
    secondBank.print("initial bank2 value");
    fifthBank.print("initial bank5 value");

    fifthBank = firstBank.addBanks(secondBank);

    firstBank.print("bank1 values after using addBanks method");
    secondBank.print("bank2 values after using addBanks method");
    fifthBank.print("bank5 values after using addBanks method");


    printSectionTitle("Using the isEqual method with 4 arguments");


    cout << "Test 1: ";
    if (fourthBank.isEqual(27, 27, 45, 38)) {
        cout << "Banks are equal" << endl;
    } else {
        cout << "Banks are not equal" << endl;
    }

    cout << "Test 2: ";
    if (fifthBank.isEqual(35, 34, 15, 7)) {
        cout << "Banks are equal" << endl;
    } else {
        cout << "Banks are not equal" << endl;
    }


    printSectionTitle("Using the isEqual method with PiggyBank object");


    cout << "Test 1: ";
    if (secondBank.isEqual(fifthBank)) {
        cout << "Banks are equal" << endl;
    } else {
        cout << "Banks are not equal" << endl;
    }

    cout << "Test 2: ";
    if (firstBank.isEqual(thirdBank)) {
        cout << "Banks are equal" << endl;
    } else {
        cout << "Banks are not equal" << endl;
    }

    
    printSectionTitle("Current values in the bank objects");


    firstBank.print("Bank1 object");
    secondBank.print("Bank2 object");
    thirdBank.print("Bank3 object");
    fourthBank.print("Bank4 object");
    fifthBank.print("Bank5 object");


    printSectionTitle("Using the isLessThan method with 4 arguments");


    cout << "Test 1: ";
    if (firstBank.isLessThan(12, 33, 42, 108)) {
        cout << "Bank1 is less than other bank" << endl;
    } else {
        cout << "Bank1 is not less than other bank" << endl;
    }

    cout << "Test 2: ";
    if (secondBank.isLessThan(3, 4, 70, 3)) {
        cout << "Bank2 is less than other bank" << endl;
    } else {
        cout << "Bank2 is not less than other bank" << endl;
    }


    printSectionTitle("Using the isLessThan method with PiggyBank object");


    cout << "Test 1: ";
    if (thirdBank.isLessThan(fifthBank)) {
        cout << "Bank3 is less than other bank" << endl;
    } else {
        cout << "Bank3 is not less than other bank" << endl;
    }

    cout << "Test 2: ";
    if (fourthBank.isLessThan(secondBank)) {
        cout << "Bank4 is less than other bank" << endl;
    } else {
        cout << "Bank4 is not less than other bank" << endl;
    }


    printSectionTitle("Using the getCoin method");

    cout << "bank1 contains " <<firstBank.getCoin(0) << " pennies" << endl;
    cout << "bank2 contains " << secondBank.getCoin(1) << " nickels" << endl;
    cout << "bank3 contains " << thirdBank.getCoin(2) << " dimes" << endl;
    cout << "bank4 contains " << fourthBank.getCoin(3) << " quarters" << endl;
    cout << "getCoin returned " << fifthBank.getCoin(4) << " with invalid index";

    return 0;
}//end of int main()


//*************** Implement the class methods after this line ***************
//***************   DON'T FORGET TO ADD DOCUMENTATION BOXES   ***************

// Name: PiggyBank()
// Use of method: a default constructor that initializes all data members, the coins, as zero.
// Arguments:   none
PiggyBank::PiggyBank() {
    emptyTheBank();
}

// Name: PiggyBank()
// Use of method: an alternate constructor that initializes all data members, the coins, to provided arguments.
// Arguments:   int pennies: number of pennies
//              int nickels: number of nickels
//              int dimes: number of dimes
//              int quarters: number of quarters
PiggyBank::PiggyBank(int pennies, int nickels, int dimes, int quarters) {
    emptyTheBank();
    addCoins(pennies, nickels, dimes, quarters);
}

// Name: PiggyBank()
// Use of method: an alternate constructor that copies another PiggyBank instance.
// Arguments:   PiggyBank& otherBank: a pointer to another PiggyBank object
PiggyBank::PiggyBank(const PiggyBank &otherBank) {
    numPennies = otherBank.numPennies;
    numNickels = otherBank.numNickels;
    numDimes = otherBank.numDimes;
    numQuarters = otherBank.numQuarters;
}

// Name: printBank()
// Use of method: prints out how many of each coins there are
// Arguments:   none
// Value returned: none
void PiggyBank::printBank() {
    cout << "Pennies: " << numPennies << "   Nickels: " << numNickels << "    Dimes: " << numDimes << "    Quarters: " << numQuarters << endl;
}

// Name: printBankValue()
// Use of method: prints out the total dollar value of the piggy bank
// Arguments:   none
// Value returned: none
void PiggyBank::printBankValue() {
    cout << "$" << fixed << setprecision(2) << calcBankValue() << endl;
}

// Name: emptyTheBank()
// Use of method: Sets all coin numbers to zero, hence emptything the piggy bank
// Arguments:   none
// Value returned: none
void PiggyBank::emptyTheBank() {
    numPennies = 0;
    numNickels = 0;
    numDimes = 0;
    numQuarters = 0;
}

// Name: addCoins()
// Use of method: Add coins to the piggy bank and updates each coin's amount accordingly
// Arguments:   int morePennies: number of pennies to add
//              int moreNickels: number of nickels to add
//              int moreDimes: number of dimes to add
//              int moreQuarters: number of quarters to add
// Value returned: none
void PiggyBank::addCoins(int morePennies, int moreNickels, int moreDimes, int moreQuarters) {
    if (morePennies >= 0)
        numPennies += morePennies;
    else
        cout << "*** Error: cannot add a negative number of pennies ***" << endl;
    if (moreNickels >= 0)
        numNickels += moreNickels;
    else
        cout << "*** Error: cannot add a negative number of nickels ***" << endl;
    if (moreDimes >= 0)
        numDimes += moreDimes;
    else
        cout << "*** Error: cannot add a negative number of dimes ***" << endl;
    if (moreQuarters >= 0)
        numQuarters += moreQuarters;
    else
        cout << "*** Error: cannot add a negative number of quarters ***" << endl;
}

// Name: addPennies(), addNickels(), addDimes(), addQuarters()
// Use of methods: each method updates the corresponding data member, pennies, nickels, dimes, and quarters, respectively.
// Arguments:   addPennies(): int morePennies: number of pennies to add
//              addNickels(): int moreNickels: number of nickels to add
//              addDimes(): int moreDimes: number of dimes to add
//              addQuarters(): int moreQuarters: number of quarters to add
// Value returned: none
void PiggyBank::addPennies(int morePennies) {
    if (morePennies >= 0)
        numPennies += morePennies;
    else
        cout << "*** Error: cannot add a negative number of pennies ***" << endl;
}

void PiggyBank::addNickels(int moreNickels) {
    if (moreNickels >= 0)
        numNickels += moreNickels;
    else
        cout << "*** Error: cannot add a negative number of nickels ***" << endl;
}

void PiggyBank::addDimes(int moreDimes) {
    if (moreDimes >= 0)
        numDimes += moreDimes;
    else
        cout << "*** Error: cannot add a negative number of dimes ***" << endl;
}

void PiggyBank::addQuarters(int moreQuarters) {
    if (moreQuarters >= 0)
        numQuarters += moreQuarters;
    else
        cout << "*** Error: cannot add a negative number of quarters ***" << endl;
}

// Name: calcBankValue()
// Use of method: calculates the total dollar value of the piggy bank
// Arguments:   none
// Value returned: double dollarValue: bank's total dollar value
double PiggyBank::calcBankValue() {
    double dollarValue = (numPennies + numNickels * 5 + numDimes * 10 + numQuarters * 25) / 100.0;

    return dollarValue;
}

// Name: print()
// Use of method: printing a PiggyBank instance's information
// Arguments:   string label: label for the bank
// Value returned: none
void PiggyBank::print(string label) {
    cout << label << endl;
    printBank();
    printBankValue();
    cout << endl;
}

// Name: addBanks()
// Use of method: Add coins from one PiggyBank instance to another and return a new instance with the updated properties.
// Arguments:   int pennies: number of pennies from the other bank
//              int nickels: number of nickels from the other bank
//              int dimes: number of dimes from the other bank
//              int quarters: number of quarters from the other bank
//              OR
//              PiggyBank otherBank: the other bank
// Value returned: a new instance with updated properties
PiggyBank PiggyBank::addBanks(int pennies, int nickels, int dimes, int quarters) {
    return PiggyBank(numPennies + pennies, numNickels + nickels, numDimes + dimes, numQuarters + quarters);
}

PiggyBank PiggyBank::addBanks(PiggyBank otherBank) {
    return PiggyBank(otherBank.getCoin(0) + numPennies, otherBank.getCoin(1) + numNickels, otherBank.getCoin(2) + numDimes, otherBank.getCoin(3) + numQuarters);
}

// Name: isEqual()
// Use of method: Checking if another bank coin amounts are equal to another's.
// Arguments:   int pennies: number of pennies from the other bank
//              int nickels: number of nickels from the other bank
//              int dimes: number of dimes from the other bank
//              int quarters: number of quarters from the other bank
//              OR
//              PiggyBank otherBank: the other bank
// Value returned: bool: true if equal, otherwise false.
bool PiggyBank::isEqual(int pennies, int nickels, int dimes, int quarters) {
    return (pennies == numPennies and nickels == numNickels and dimes == numDimes and quarters == numQuarters) ? true : false;
}

bool PiggyBank::isEqual(PiggyBank otherBank) {
    return (numPennies == otherBank.getCoin(0) and numNickels == otherBank.getCoin(1) and numDimes == otherBank.getCoin(2) and numQuarters == otherBank.getCoin(3)) ? true : false;
}

// Name: isLessThan()
// Use of method: Checking if another bank coin amounts are less than another's.
// Arguments:   int pennies: number of pennies from the other bank
//              int nickels: number of nickels from the other bank
//              int dimes: number of dimes from the other bank
//              int quarters: number of quarters from the other bank
//              OR
//              PiggyBank otherBank: the other bank
// Value returned: bool: true if less, otherwise false.
bool PiggyBank::isLessThan(int pennies, int nickels, int dimes, int quarters) {
    PiggyBank otherBank = PiggyBank(pennies, nickels, dimes, quarters);

    return (calcBankValue() < otherBank.calcBankValue()) ? true : false;
}

bool PiggyBank::isLessThan(PiggyBank otherBank) {
    return (calcBankValue() < otherBank.calcBankValue()) ? true : false;
}

// Name: getCoin()
// Use of method: getting the amount of whichever coin.
// Arguments:   int coinIndex: indicator of which type of coin to get info on.
// Value returned: the amount of specified coin
int PiggyBank::getCoin(int coinIndex) {
    if (coinIndex == 0)
        return numPennies;
    else if (coinIndex == 1)
        return numNickels;
    else if (coinIndex == 2)
        return numDimes;
    else if (coinIndex == 3)
        return numQuarters;
    else 
        return -1;
}

// Name: printSectionTitle()
// Use of method: displays a title that helps separate the output produced by the program.
// Arguments:   string title: title that is displayed
// Value returned: none
void printSectionTitle(string title) {
    cout << endl << endl
         << "-------------------------------------------------"
         << endl
         << title
         << endl << endl;
}