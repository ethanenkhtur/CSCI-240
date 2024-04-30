/***************************************************************
CSCI 240         Program 10     Spring 2024

Name: Ethan Enkhtur

Section: 0001

Due Date: 04/26/24

Purpose: Implement a class called PiggyBank that will be used to represent a collection of coins. Functionality will be added to the class.
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

}

int main() {}

Employee::Employee() {
    strcpy(name, "None");
    setIDnum("ACB1234");
    setSalary(0);
}

Employee::Employee(const char newName[], const char id[], double newSalary) {
    strcpy(newName, name);
    setIDnum(id);
    setSalary(newSalary);
}

void Employee::display() {
    cout << left << setw(30) << name
         << right << setw(10) << id
         << endl
         << left << fixed << setprecision(2) << "$" << salary << endl;
}

void Employee::increaseSalary(double raise) {
    if (raise > 0) 
        salary += raise;
    else
        cout << "Error: salary increase is invalid - negative or 0.00. Salary was not changed." << endl;
}

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
        cout << "Error: new id is invalid - not 7 characters. ID was not changed." << endl;
    } else if (!alphabetics) {
        cout << "Error: new id is invalid - not first 3 alphabetics. ID was not changed." << endl;
    } else if (!digits) {
        cout << "Error: new id is invalid - not last 4 digits. ID was not changed." << endl;
    } else {
        strcopy(id, updated_id);
    }
}

void Employee::setSalary(double updated_salary) {
    if (updated_salary > 0) {
        salary = updated_salary;
    } else {
        cout << "Error: new salary is invalid - negative or 0.00. Salary was not changed." << endl;
    }
}

const char * Employee::getName() {
    return name;
}

const char * Employee::getIDnum() {
    return id;
}

double Employee::getSalary() {
    return salary;
}