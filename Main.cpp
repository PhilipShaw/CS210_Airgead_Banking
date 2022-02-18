// Course: CS210, Student: Philip Shaw, Date: 02/06/22

#include <iostream>
#include <iomanip>
#include <string>
#include "UserFigures.h"
#include "DisplayElements.h"

using namespace std;

int main() {

    // Instantiate objects from the classes created to store and compute user input:  
    UserFigures studentFinance;
    DisplayElements displayDecorations;
    
    // Initialize placeholder variables for user input:
    double initalInvestmentAmount = NULL;
    double monthlyDepositAmount = NULL;
    double annualInterestRate = NULL;
    int totalYears = NULL;

    // Display example for user:
    displayDecorations.DisplayBlankTemplate();
   
    // Request User Input and store it privately:
    studentFinance.RequestUserInput(initalInvestmentAmount, monthlyDepositAmount, annualInterestRate, totalYears);

    // Reset placeholders for user privacy:
    initalInvestmentAmount = NULL;
    monthlyDepositAmount = NULL;
    annualInterestRate = NULL;
    totalYears = NULL;


    // Display results for user (without additional monthly deposits):
    studentFinance.TableWithoutDeposits(studentFinance.GetinitialInvestmentAmount(),
        studentFinance.GetAPR(), studentFinance.GetYears());

    // Display results for user (with additional monthly deposits):
    studentFinance.TableWithDeposits(studentFinance.GetinitialInvestmentAmount(),
        studentFinance.GetMonthlyDeposit(), studentFinance.GetAPR(), studentFinance.GetYears()); 

    return 0;
}