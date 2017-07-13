#include "Account.h"

using namespace std;

namespace ict{ 
	
	// constructor   
	Account::Account(double bal)
	{
		if (bal >= 0)
		{
			this->balance = bal;
		}
		else
		{
			this->balance = 1;
		}
	}
	// credit (add) an amount to the account balance
	void Account::credit(double bal)
	{
		this->balance += bal;
	}
	
	// debit (subtract) an amount from the account balance return bool 
	bool Account::debit(double bal)
	{
		bool i = false;
		if (this->balance - bal > 0)
		{
			this->balance -= bal;
			i = true;
		}
		return i;
	}

	void Account::display(ostream& os)
	{
		os.setf(ios::fixed);
		os.precision(2);
		os << "Balance: $ " << this->balance << endl;
	}

	double Account::getBalance() const
	{
		return balance;
	} 

	void Account::setBalance( double newBalance )
	{
		balance = newBalance;
	} 
}