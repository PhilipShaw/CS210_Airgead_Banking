// Course: CS210, Student: Philip Shaw, Date: 02/06/22

#include <iostream>
#include <string>
#include "DisplayElements.h"

using namespace std;

// This class was created for potential expansion of the Airgead Banking financial
// calculator.

/*
    DisplayElements: class constructor.
*/
DisplayElements::DisplayElements() {}


/*
    DisplayBlankTemplate: Prints a header demonstrating the programs required input 
    values. 
*/
void DisplayElements::DisplayBlankTemplate() {
    cout << "********************************" << endl;
    cout << "********** Data Input **********" << endl;
    cout << "Initial Investment Amount: " << endl;
    cout << "Monthly Deposit: " << endl;
    cout << "Annual Interest: " << endl;
    cout << "Number of years: " << endl;
    cout << endl;
}