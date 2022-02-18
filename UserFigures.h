// Course: CS210, Student: Philip Shaw, Date: 02/06/22

#ifndef USER_FIGURES_H
#define USER_FIGURES_H

#include <iostream>
#include <iomanip>
#include "DisplayElements.h"
#include <string>

using namespace std;

class UserFigures {

public:
	// CONSTRUCTOR:
	UserFigures();

	// MUTATORS:
	void SetinitialInvestmentAmount(double t_initInvestment);
	void SetMonthlyDeposit(double t_monthlyContribution);
	void SetAPR(double t_percentageRate);
	void SetYears(int t_numYears);


	// ACCESSORS:
	double GetinitialInvestmentAmount() const;
	double GetMonthlyDeposit() const;
	double GetAPR() const;
	int GetYears() const;

	// HYBRID members (these accessors return calculated values without altering private
	// data members):
	void RequestUserInput(double t_initialInvestment, double t_monthlyDeposit, 
		double t_APR, int t_numberOfYears);
	void TableWithoutDeposits(double t_initialInvestment, double t_APR, int t_numberOfYears);
	void TableWithDeposits(double t_initialInvestment, double t_monthlyDeposit, 
		double t_APR, int t_numberOfYears);


// Monetary values are kept private for user confidentiality:
private:
	double m_initialInvestmentAmount = NULL;
	double m_monthlyDeposit = NULL;
	double m_APR = NULL;
	int m_totalYears = NULL;
};

#endif 