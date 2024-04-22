/***************************************************************
CSCI 240         Program 8     Spring 2024

Name: Ethan Enkhtur

Section: 0001

Due Date: 04/19/24

Purpose: Implement a class called PiggyBank that will be used to represent a collection of coins. Functionality will be added to the class so that coins can be added to the bank and output operations can be performed.
***************************************************************/


#include <iostream>
#include <iomanip>

using namespace std;

//*************** Place the class description after this line ***************

class PiggyBank {
    int numPennies, numNickels, numDimes, numQuarters;

    public: 
        PiggyBank();

        void printBank();
        void printBankValue();
        void emptyTheBank();
        void addCoins(int, int, int, int);
        void addNickels(int);
        void addPennies(int);
        void addDimes(int);
        void addQuarters(int);
        double calcBankValue();

};


//****************************************************************************

int main() {
    //Test 1 -- default constructor and printPiggyBank
    cout << "***** Test 1: Default Constructor and printPiggyBank *****" << endl << endl;
    cout << fixed << setprecision(2);

    //create two objects using the default constructor
    PiggyBank bank1;
    PiggyBank bank2 = PiggyBank();

    //display the two objects
    cout << "bank1:" << endl;

    bank1.printBank();

    cout << endl << endl << "bank2:" << endl;

    bank2.printBank();


    //Test 2 -- printBankValue
    cout << endl << endl << endl << "***** Test 2: printBankValue *****" << endl << endl
        << "bank1:" << endl;

    bank1.printBank();

    cout << endl << "Total: ";

    bank1.printBankValue();


    //Test 3 -- adding coins
    cout << endl << endl << endl << "***** Test 3: addCoins Method *****" << endl << endl
        << "3a: Adding 2 pennies, 47 nickels, 20 dimes, and 5 quarters to bank1 produces:"
        << endl << endl;

    //update bank 1: 2 pennies, 47 nickels, 20 dimes, and 5 quarters   and display
    bank1.addCoins( 2, 47, 20, 5 );

    bank1.printBank();

    cout << endl << "Total: ";

    bank1.printBankValue();


    //update bank 2: 143 pennies, 9 nickels, 0 dimes, and 44 quarters   and display
    bank2.addCoins( 143, 9, 0, 44 );

    cout << endl << endl << "3b: Adding 143 pennies, 9 nickels, 0 dimes, and 44 quarters to bank2 produces:"
        << endl << endl;

    bank2.printBank();

    cout << endl << "Total: ";

    bank2.printBankValue();


    //Test 4 -- adding pennies
    cout << endl << endl << endl << "***** Test 4: addPennies Method *****" << endl << endl
        << "4a: Adding 95 pennies to bank1:" << endl << endl;

    //update bank 1: 95 pennies   and display
    bank1.addPennies( 95 );

    bank1.printBank();

    cout << endl << "Total: ";

    bank1.printBankValue();


    cout << endl << endl << "4b: Adding -54 pennies to bank1:" << endl << endl;

    //(try to) update bank 1: -54 pennies   and display
    bank1.addPennies( -54 );

    bank1.printBank();

    cout << endl << "Total: ";

    bank1.printBankValue();


    //Test 5 -- adding nickels
    cout << endl << endl << endl << "***** Test 5: addNickels Method *****" << endl << endl
        << "5a: Adding -12 nickels to bank2:" << endl << endl;

    //(try to) update bank 2: -12 nickels   and display
    bank2.addNickels( -12 );

    bank2.printBank();

    cout << endl << "Total: ";

    bank2.printBankValue();


    cout << endl << endl << "5b: Adding 17 nickels to bank2:" << endl << endl;

    //update bank 2: 17 nickels   and display
    bank2.addNickels(17);

    bank2.printBank();

    cout << endl << "Total: ";

    bank2.printBankValue();



    //Test 6 -- adding dimes
    cout << endl << endl << endl << "***** Test 6: addDimes Method *****" << endl << endl
        << "6a: Adding 157 dimes to bank2:" << endl << endl;

    //update bank 2: 157 dimes   and display
    bank2.addDimes( 157 );

    bank2.printBank();

    cout << endl << "Total: ";

    bank2.printBankValue();

    cout << endl << endl << "6b: Adding -37 dimes to bank2:" << endl << endl;

    //(try to) update bank 2: -37 dimes   and display
    bank2.addDimes( -37 );

    bank2.printBank();

    cout << endl << "Total: ";

    bank2.printBankValue();



    //Test 7 -- adding quarters
    cout << endl << endl << endl << "***** Test 7: addQuarters Method *****" << endl << endl
        << "7a: Adding 14 quarters to bank1: " << endl << endl;

    //update bank 1: 14 quarters   and display
    bank1.addQuarters( 14 );

    bank1.printBank();

    cout << endl << "Total: ";

    bank1.printBankValue();


    cout << endl << endl << "7b: Adding -45 quarters to bank1:" << endl << endl;

    //(try to) update bank 1: -45 quarters   and display
    bank1.addQuarters( -45 );

    bank1.printBank();

    cout << endl << "Total: ";

    bank1.printBankValue();



    //Test 8 -- bank value
    cout << endl << endl << endl << "***** Test 8: Calculating the Bank Values *****" << endl << endl;

    //Get the current value of both banks and calculate the total amount of money
    double bank1value = bank1.calcBankValue(),
        bank2value = bank2.calcBankValue();

    double total = bank1value + bank2value;

    //display the calculated total
    cout << "$" << bank1value << " + $" << bank2value << " = $" << total << endl << endl;


    //Test 9 -- empty the bank
    cout << endl << endl << endl << "***** Test 9: Emptying the PiggyBanks *****" << endl << endl
        << "It\'s time to empty the banks!" << endl << endl;

    cout << endl << "9a: bank1 initially contains: " << endl << endl;

    //display the current value of bank1 and the updated value after it has been emptied
    bank1.printBank();

    cout << endl << "Total: ";

    bank1.printBankValue();

    bank1.emptyTheBank();

    cout << endl << endl << "bank1 now contains: " << endl << endl;

    bank1.printBank();

    cout << endl << "Total: ";

    bank1.printBankValue();



    cout << endl << endl << endl << "9b: bank2 initially contains: " << endl << endl;

    //display the current value of bank2 and the updated value after it has been emptied
    bank2.printBank();

    cout << endl << "Total: ";

    bank2.printBankValue();

    bank2.emptyTheBank();

    cout << endl << endl << "bank2 now contains: " << endl << endl;

    bank2.printBank();

    cout << endl << "Total: ";

    bank2.printBankValue();



    cout << endl << endl;

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