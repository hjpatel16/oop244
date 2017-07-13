#include "SavingsAccount.h"

using namespace std;

namespace ict{ 
	
	// TODO: Implement SavingsAccount member functions here
	SavingsAccount::SavingsAccount(double bal, double ir) : Account(bal)
	{
		if (ir > 0)
		{
			this->interestRate = ir;
		}
		else
		{
			this->interestRate = 0;
		}
	}

	double SavingsAccount::calculateInterest()
	{
		return (this->interestRate * this->getBalance());
	}

	void SavingsAccount::display(std::ostream& ostr)
	{
		ostr << "Account type: Saving" << endl;
		Account::display(ostr);
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << "Interest Rate (%): " << this->interestRate * 100 << endl;
	}
}