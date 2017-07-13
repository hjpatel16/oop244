#include "CheckingAccount.h"

using namespace std;

namespace ict{    
	
	// TODO: define CheckingAccount class member functions here  
	CheckingAccount::CheckingAccount(double bal, double trf) : Account(bal)
	{
		if (trf > 0)
		{
			this->transactionFee = trf;
		}
		else
		{
			this->transactionFee = 0;
		}
	}

	void CheckingAccount::chargeFee()
	{
		double i = Account::getBalance();
		i -= this->transactionFee;
		Account::setBalance(i);
	}

	bool CheckingAccount::debit(double a)
	{
		bool k = false;
		k = Account::debit(a);
		if (k)
		{
			chargeFee();
			k = true;
		}
		return k;
	}

	void CheckingAccount::credit(double bal)
	{
		Account::credit(bal);
		chargeFee();
	}

	void CheckingAccount::display(std::ostream& o)
	{
		o << "Account type: Checking" << endl;
		Account::display(o);
		o.setf(ios::fixed);
		o.precision(2);
		o << "Transaction Fee: " << this->transactionFee << endl;
	}
}