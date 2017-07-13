#include<cstring>
#include "CreditCard.h"

namespace sict {

	void CreditCard::name(const char cardHolderName[])
	{
		strcpy(m_cardHolderName, cardHolderName);
	}

	void CreditCard::initialize(unsigned long long creditCardNumber, int instCode, int expiryYear, int expiryMonth, int numberInTheBack)
	{
		m_cardNumber = creditCardNumber;
		m_institutionCode = instCode;
		m_expiryMonth = expiryMonth;
		m_expiryYear = expiryYear;
		m_numberInTheBack = numberInTheBack;
	}

	bool CreditCard::isValid() const
	{
		return(m_cardHolderName[0] != '\0' &&
			m_cardNumber >= MIN_CARD_NUMBER &&
			m_cardNumber <= MAX_CARD_NUMBER &&
			m_institutionCode >= MIN_INST_NUMBER &&
			m_institutionCode <= MAX_INST_NUMBER &&
			m_expiryYear >= MIN_EXP_YEAR &&
			m_expiryYear <= MAX_EXP_YEAR &&
			m_expiryMonth >= 1 && m_expiryMonth <= 12 &&
			m_numberInTheBack > 0 && m_numberInTheBack < 1000);
	}

	void CreditCard::write() const
	{
		if (isValid())
		{
			cout << "Cardholder: " << m_cardHolderName << endl

				<< "Card Number: " << m_cardNumber << endl

				<< "Institution: " << m_institutionCode << endl

				<< "Expires: " << m_expiryMonth << "/" << m_expiryYear << endl

				<< "Number at the back: " << m_numberInTheBack;
		}

	}

	void CreditCard::write(bool displayName) const
	{
		if (displayName == false)
		{
			writeCardInfo();
		}
	}

	void CreditCard::write(bool displayName, bool displayCardInfo) const
	{
		if (displayName == true && displayCardInfo == false)
		{
			writeName();
		}

		if (displayName == false && displayCardInfo == false)
		{

		}
	}

	void CreditCard::writeName() const
	{
		cout << "Cardholder: " << m_cardHolderName;
	}

	void CreditCard::writeCardInfo() const
	{
		cout<< "Card Number: " << m_cardNumber << endl

			<< "Institution: " << m_institutionCode << endl

			<< "Expires: " << m_expiryMonth << "/" << m_expiryYear << endl

			<< "Number at the back: " << m_numberInTheBack;
	}
}
