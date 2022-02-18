// Course: CS210, Student: Philip Shaw, Date: 02/06/22

#include "UserFigures.h"

using namespace std;

// ******** CONSTRUCTOR ********:
UserFigures::UserFigures() {}

// ******** MUTATOR MEMBERS in UserFigures class ********:


/*
    SetinitialInvestmentAmount: sets the calculation's initial investment amount.
*/
void UserFigures::SetinitialInvestmentAmount(double t_initInvestment) {
	m_initialInvestmentAmount = t_initInvestment;
}


/*
    SetMonthlyDeposit: sets the calculation's recurring monthly deposit.
*/
void UserFigures::SetMonthlyDeposit(double t_monthlyContribution) {
	m_monthlyDeposit = t_monthlyContribution;
}
void UserFigures::SetAPR(double t_percentageRate) {
	m_APR = t_percentageRate;
}


/*
    SetYears: sets the total number of years that the investment will be compounded.
*/
void UserFigures::SetYears(int t_numYears) {
	m_totalYears = t_numYears;
}


// ******* ACCESSOR MEMBERS in UserFigures class ********:

/*
    GetinitialInvestmentAmount: returns the stored initial investment amount.
*/
double UserFigures::GetinitialInvestmentAmount() const {
	return m_initialInvestmentAmount;
}


/*
    GetMonthlyDeposit: returns the stored recurring monthly deposit figure.
*/
double UserFigures::GetMonthlyDeposit() const {
	return m_monthlyDeposit;
}


/*
    GetAPR: returns the stored annual percentage rate of return.
*/
double UserFigures::GetAPR() const {
	return m_APR;
}


/*
    GetYears: returns the stored number of years until investment matures.
*/
int UserFigures::GetYears() const {
	return m_totalYears;
}


/*
    RequestUserInput: prints a header and prompts the user for the required input
    parameters:

    t_initialInvestment - the initial investent amount
    t_monthlyDeposit - an amount to be invested every month until the account matures
    t_APR - the annual percentage rate earned on the principal value before compounding
    t_numberOfYears - the total number of years that the investment will mature

*/
void UserFigures::RequestUserInput(double t_initialInvestment, double t_monthlyDeposit,
    double t_APR, int t_numberOfYears) {

    // Print header:
    cout << "********************************" << endl;
    cout << "********** Data Input **********" << endl;

    // Prompt user:
    cout << "Initial Investment Amount: $";


    // Get input using while while loop to validate data:
    while (!(cin >> t_initialInvestment) || t_initialInvestment < 0.00) {
        cout << "Invalid input. Please enter a valid deposit amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Set private data member: 
    UserFigures::SetinitialInvestmentAmount(t_initialInvestment);

    // Prompt user:
    cout << "Monthly Deposit: $";

    // Get input using while while loop to validate data:
    while (!(cin >> t_monthlyDeposit) || t_monthlyDeposit < 0.00) {
        cout << "Invalid input. Please enter a valid deposit amount";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Set private data member:
    UserFigures::SetMonthlyDeposit(t_monthlyDeposit);

    // Prompt user:
    cout << "Annual Interest: %";

    // Get input using while while loop to validate data:
    while (!(cin >> t_APR)) {
        cout << "Invalid input. Please enter numbers only: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Set private data member:
    UserFigures::SetAPR(t_APR);

    // Prompt user:
    cout << "Number of years: ";

    // Get input using while while loop to validate data:
    while (!(cin >> t_numberOfYears) || t_numberOfYears < 1) {
        cout << "Invalid input. Please enter positive numbers only: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Set private data member:
    UserFigures::SetYears(t_numberOfYears);

    // Clear the buffer stream:
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << endl << endl;
}


/*
    TableWithDeposits: uses argument data to calculate future investment returns 
    (with monthly contributions) then prints the information to the screen. 
    
    Parameters:

    t_initialInvestment - the initial investent amount
    t_monthlyDeposit - an amount to be invested every month until the account matures
    t_APR - the annual percentage rate earned on the principal value before compounding
    t_numberOfYears - the total number of years that the investment will mature

*/
void UserFigures::TableWithDeposits(double t_initialInvestment, double t_monthlyDeposit,
    double t_APR, int t_numberOfYears) {

    // Holds a running total of the principal being compounded:
    double totalPrincipal = t_initialInvestment;

    // Output table header to the console:
    cout << "        Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "==========================================================================";
    cout << "=" << endl;
    cout << "   Year" << " " << setw(25) << "Year End Balance" << " " << setw(35);
    cout << "Year End Earned Interest" << endl;
    cout << "--------------------------------------------------------------------------";
    cout << "-" << endl;

    // Main loop to calculate the total earnings of the investment year after year:
    for (int i = 0; i < t_numberOfYears; ++i) {

        // Holds the total interest earned for the individual year: 
        double yearlyEarnings = 0;

        // Holds the running monthly interest earnings (within the inner loop):
        double monthlyEarnings;

        // Nested loop to compound the principal value monthly each year:
        for (int j = 0; j < 12; ++j) {            

            // Determine the monthly interest earned:
            monthlyEarnings = (totalPrincipal + t_monthlyDeposit) *
                ((t_APR / 100) / 12);

            // Add the current month's earnings to the current year's earnings:
            yearlyEarnings = yearlyEarnings + monthlyEarnings;

            // Compound the running total principal value (including the monthly 
            // deposit):
            totalPrincipal = totalPrincipal + t_monthlyDeposit + 
                monthlyEarnings;
        }
        
        // Populate current table row with investment data:        
        cout << setprecision(2) << fixed << setw(6) << (i + 1);
        cout << setw(30 - to_string(totalPrincipal).size()) << " " << right;
        cout << setw(1) << "$" << right;
        cout << setw(10 - to_string(totalPrincipal).size()) << totalPrincipal << right;
        cout << setw(39 - to_string(yearlyEarnings).size()) << " " << right; 
        cout << setw(1) << "$" << right; 
        cout << setw(2 - to_string(yearlyEarnings).size()) << yearlyEarnings << right;
        cout << endl << endl;
        
    }
    cout << endl;
}


/*
    TableWithoutDeposits: uses provided data to calculate future investment returns
    (without monthly contributions) then prints the information to the screen.

    Parameters:

    t_initialInvestment - the initial investent amount
    t_monthlyDeposit - an amount to be invested every month until the account matures
    t_APR - the annual percentage rate earned on the principal value before compounding
    t_numberOfYears - the total number of years that the investment will mature

*/
void UserFigures::TableWithoutDeposits(double t_initialInvestment, 
    double t_APR, int t_numberOfYears) {

    // Holds a running total of the principal being compounded:
    double totalPrincipal = t_initialInvestment;

    // Table header for the console output:
    cout << "        Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "==========================================================================";
    cout << "=" << endl;
    cout << "   Year" << " " << setw(25) << "Year End Balance" << " " << setw(35);
    cout << "Year End Earned Interest" << endl;
    cout << "--------------------------------------------------------------------------";
    cout << "-" << endl;

    // Main loop to calculate the total earnings of the investment year after year:
    for (int i = 0; i < t_numberOfYears; ++i) {

        // Holds the total interest earned for the individual year: 
        double yearlyEarnings = 0;

        // Holds the running monthly interest earnings for one year (within the inner 
        // loop):
        double monthlyEarnings;

        // Nested loop to compound the principal value each month (for the current year):
        for (int j = 0; j < 12; ++j) {

            // Determine the monthly interest earned:
            monthlyEarnings = (totalPrincipal) *
                ((t_APR / 100) / 12);

            // Add the current month's earnings to the current year's earnings:
            yearlyEarnings = yearlyEarnings + monthlyEarnings;

            // Compound the running total principal value:
            totalPrincipal = totalPrincipal + monthlyEarnings;
        }

        // Populate current table row with investment data:
        cout << setprecision(2) << fixed << setw(6) << (i + 1);
        cout << setw(30 - to_string(totalPrincipal).size()) << " " << right;
        cout << setw(1) << "$" << right;
        cout << setw(10 - to_string(totalPrincipal).size()) << totalPrincipal << right;
        cout << setw(39 - to_string(yearlyEarnings).size()) << " " << right;
        cout << setw(1) << "$" << right;
        cout << setw(2 - to_string(yearlyEarnings).size()) << yearlyEarnings << right;
        cout << endl << endl;
    }
    cout << endl << endl;
}