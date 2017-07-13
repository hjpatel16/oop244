
#ifndef CREDITCARD_H
#define CREDITCARD_H

#include<iostream>

using namespace std;
const int MAX_NAME_LENGTH = 40;
const int MIN_INST_NUMBER = 100;
const int MAX_INST_NUMBER = 999;
const int MIN_EXP_YEAR = 2017;
const int MAX_EXP_YEAR = 2037;
const unsigned long long MIN_CARD_NUMBER = 4000000000000000;
const unsigned long long MAX_CARD_NUMBER = 4000999999999999;


namespace sict {


	class CreditCard {

		char m_cardHolderName[MAX_NAME_LENGTH];
		unsigned long long m_cardNumber;
		int	m_institutionCode;
		int m_expiryYear;
		int m_expiryMonth;
		int	m_numberInTheBack;

	public :
		void name(const char[]);
		void initialize(unsigned long long, int , int , int , int);
		void write() const;
		bool isValid() const;




	};
}

#endif
