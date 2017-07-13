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
		long long arr[20], a, b;
		long c, d;
		 if (name != nullptr && name[0] != '\0' && pharr != nullptr && nof != 0)
		{
			strncpy(this->m_name, name,20);
			for (i = 0; i < nof; i++)
			{
				 a = pharr[i] / 10000000000;
				 b = pharr[i] % 10000000000;
				 c = b / 10000000;
				 d = b % 10000000; 
				if (a < 99 && a != 0 && c > 99 && c < 999 && c != 0 && d > 999999 && d < 9999999)
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
				for (int i = 0; i < 20; i++)
				{
					cout << this->m_name[i];
				}
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
			this->m_phoneNumbers == nullptr);

	}
	Contact::~Contact()
	{
		//delete[] m_phoneNumbers;
		m_noOfPhoneNumbers = 0;
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
					cout << "(+" << m_phoneNumbers[i] / 10000000000 << ") " << (m_phoneNumbers[i] % 10000000000) / 10000000 << " " << (m_phoneNumbers[i] % 10000000) / 10000 << "-" << (m_phoneNumbers[i] % 10000000) % 10000 << endl;
				}

			}
		
		}
	}


