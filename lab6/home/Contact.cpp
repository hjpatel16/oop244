#include<iostream>
#include<cstring>
#include "Contact.h"

using namespace std;

namespace communication
{
	Contact::Contact()
	{
		this->m_name[0] = '\0';
		this->m_noOfPhoneNumbers = 0;
		this->m_phoneNumbers = 0;
	}
	Contact::Contact(const char* name, long long pharr[], int nof)
	{
		int i;
		int k = 0;
		bool valid;
		long long arr[20];
		valid = (name != nullptr && name[0] != '\0' && pharr != nullptr);
		if (valid)
		{
			strncpy(this->m_name, name,20);
			for (i = 0; i < nof; i++)
			{
				long long a = pharr[i] / 10000000000;
				long long b = pharr[i] % 10000000000;
				long long c = b / 10000000;
				long long d = b % 10000000;
				valid = a < 99 && a != 0 && c > 99 && c < 999 && c != 0 && d > 999999 && d < 9999999;
				if (valid)
				{
					arr[k] = pharr[i];
					k++;
				}
			}
			this->m_noOfPhoneNumbers = k;
			this->m_phoneNumbers = new long long[this->m_noOfPhoneNumbers];
			for (int j = 0; j < this->m_noOfPhoneNumbers; j++)
			{
				this->m_phoneNumbers[j] = arr[j];
			}
		}
		else
		{
			if (name != nullptr && name[0] != '\0')
			{
				strncpy(this->m_name, name, 20);
				cout << this->m_name << endl;
				this->m_noOfPhoneNumbers = 0;
				this->m_phoneNumbers = nullptr;
			}
			else
			{
				this->m_name[0] = '\0';
				this->m_noOfPhoneNumbers = 0;
				this->m_phoneNumbers = 0;
			}
		}
	}
	bool Contact::isEmpty() const
	{
		return (this->m_name[0] == '\0' &&
			this->m_noOfPhoneNumbers == 0 &&
			this->m_phoneNumbers == 0);

	}
	void Contact::display() const
	{
		if (this->isEmpty())
		{
			cout << "Empty contact!" << endl;
		}
		else
		{
			for (int i = 0; i < 20; i++)
			{
				cout << this->m_name[i];
			}
			cout << endl;
		for (int i = 0; i < this->m_noOfPhoneNumbers; i++)
		{
			long long a = this->m_phoneNumbers[i] / 10000000000;
			long long b = this->m_phoneNumbers[i] % 10000000000;
			long long c = b / 10000000;
			long long d = b % 10000000;
			long e = d / 10000;
			long f = d % 10000;
			cout << "+(" << a << ") " << c << " " << e << "-" << f << endl;
		}
		}
	}

	Contact::Contact(const Contact& other)
	{
		strcpy(this->m_name, other.m_name);
		this->m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;

		if (other.m_phoneNumbers != nullptr)
		{
			this->m_phoneNumbers = new long long[this->m_noOfPhoneNumbers];
			for (int i = 0; i < this->m_noOfPhoneNumbers; i++)
			{
				this->m_phoneNumbers[i] = other.m_phoneNumbers[i];
			}
		}
		else
		{
			this->m_phoneNumbers = nullptr;
		}
	}

	Contact& Contact::operator=(const Contact& other)
	{
		if (this != &other)
		{
			delete[] this->m_phoneNumbers;
			strcpy(this->m_name, other.m_name);
			this->m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;

			if (other.m_phoneNumbers != nullptr)
			{
				this->m_phoneNumbers = new long long[other.m_noOfPhoneNumbers];
				for (int i = 0; i < this->m_noOfPhoneNumbers; i++)
				{
					this->m_phoneNumbers[i] = other.m_phoneNumbers[i];
				}
			}
		
		}
		return *this;
	}

	Contact::~Contact()
	{
		delete[] m_phoneNumbers;
	}
	void Contact::addPhoneNumber(long long phoneNumber)
	{

		if (10000000000 <= phoneNumber && phoneNumber <= 999999999999)

		{
			if (this->m_noOfPhoneNumbers == 0)
			{
				this->m_phoneNumbers = new long long[4];
			}
		}
		this->m_phoneNumbers[this->m_noOfPhoneNumbers] = phoneNumber;
		this->m_noOfPhoneNumbers = this->m_noOfPhoneNumbers + 1;

	}
}
