/***************************************************************
CSCI 240         Program 10     Spring 2024

Name: Ethan Enkhtur

Section: 0001

Due Date: 05/02/24

Purpose: Implement a class called Employee that will be used to hold the information for an
employee.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>

using namespace std;

class Employee {
    private:
        char name[30];
        char id[8];
        double salary;

    public:
        Employee();
        Employee(const char[], const char[], double);

        void display();
        void increaseSalary(double);

        void setIDnum(const char[]);
        void setSalary(double);

        const char * getName();
        const char * getIDnum();
        double getSalary();

};

int main() {
    Employee first_employee = Employee("Ethan Enkhtur", "NIU4274", 53498.61);

    cout << "The first Employee object:" << endl;
    first_employee.display();
    first_employee.increaseSalary(125.15);
    first_employee.display();


    Employee second_employee = Employee();

    cout << endl << endl << "The second Employee object:" << endl;
    second_employee.display();
    second_employee.increaseSalary(-2200.00);
    second_employee.display();


    Employee third_employee = Employee("Blanche Devereaux", "TGG1985", 820.12);

    cout << endl << endl << "The third Employee object:" << endl;
    third_employee.display();
    third_employee.setSalary(82.88);
    third_employee.setIDnum("TGP1992");
    third_employee.display();


    Employee fourth_employee = Employee("Grace Hopper", "UNI1950", 2468.00);

    cout << endl << endl << "The fourth Employee object:" << endl;
    fourth_employee.display();
    fourth_employee.setIDnum("COBOL1959");
    fourth_employee.increaseSalary(9517.53);
    cout << fourth_employee.getName() << " has a salary of " << fourth_employee.getSalary() << endl << endl;
    fourth_employee.display();


    Employee fifth_employee = Employee("Charlie Hudson", "REX2332", 71940.76);

    cout << endl << endl << "The fifth Employee object:" << endl;
    fifth_employee.display();
    fifth_employee.setSalary(-10000.01);
    cout << endl << "Employee 5 has an identification number of " << fifth_employee.getIDnum() << endl << endl;
    fifth_employee.display();
}

// Name: Employee()
// Use of method: a default constructor that initializes all data members to default values.
// Arguments:   none
Employee::Employee() {
    strcpy(name, "None");
    setIDnum("ACB1234");
    salary = 0;
}

// Name: Employee()
// Use of method: a alternate constructor that initializes all data members to given parameters.
// Arguments:   none
Employee::Employee(const char newName[], const char id[], double newSalary) {
    strcpy(name, newName);
    setIDnum(id);
    setSalary(newSalary);
}

// Name: display()
// Use of method: Displays information about employee
// Arguments:   none
void Employee::display() {
    cout << left << setw(30) << name
         << right << setw(10) << id
         << endl
         << left << fixed << setprecision(2) << "$" << salary << endl << endl;
}

// Name: increaseSalary()
// Use of method: a method that increases employee's salary by a valid given amount
// Arguments:   double salary: amount to increase salary by.
void Employee::increaseSalary(double raise) {
    if (raise > 0) 
        salary += raise;
    else
        cout << "Error: salary increase is invalid - negative or 0.00. Salary was not changed." << endl << endl;
}

// Name: setIDnum()
// Use of method: updates an employee's id to a valid new id.
// Arguments:   const char updated_id[]: new id to update old id by.
void Employee::setIDnum(const char updated_id[]) {

    bool digits = true, alphabetics = true;

    for (int i = 0; i < 3; i++) {
        if (!isalpha(updated_id[i]))
            alphabetics = false;
    }

    for (int i = 3; i < 7; i++) {
        if (!isdigit(updated_id[i]))
            digits = false;
    }


    if (strlen(updated_id) != 7) {
        cout << "Error: new id is invalid - not 7 characters. ID was not changed." << endl << endl;
    } else if (!alphabetics) {
        cout << "Error: new id is invalid - not first 3 alphabetics. ID was not changed." << endl << endl;
    } else if (!digits) {
        cout << "Error: new id is invalid - not last 4 digits. ID was not changed." << endl << endl;
    } else {
        strcpy(id, updated_id);
    }
}

// Name: setSalary()
// Use of method: a method that sets an employee's salary to a new valid amount.
// Arguments:   double updated_salary: new updated salary.
void Employee::setSalary(double updated_salary) {
    if (updated_salary > 0) {
        salary = updated_salary;
    } else {
        cout << "Error: new salary is invalid - negative or 0.00. Salary was not changed." << endl;
    }
}

// Name: getName(), getIDnum(), getSalary()
// Use of method: accessor methods that return the info in each data members.
// Arguments:   none
// Values returned: each appropriate data member.
const char * Employee::getName() {
    return name;
}

const char * Employee::getIDnum() {
    return id;
}

double Employee::getSalary() {
    return salary;
}