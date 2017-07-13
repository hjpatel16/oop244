// TODO: add your headers here
#include <iostream>
#include<cstring>
#include<string>
#include "passenger.h"
// TODO: add the namespaces that you will be using here
using namespace std;
// TODO: holiday namespace here
namespace holiday
{

	// TODO: add the default constructor here
	Passenger::Passenger()
	{
		m_name[0] = '\0';
		m_destination[0] = '\0';
		m_departureYear = 0;
		m_departureDay = 0;
		m_departureMonth = 0;
	}



	// TODO: add the constructor with 5 parameters here
	Passenger::Passenger(const char name[], const char dest[], int y , int m, int d)
	{
		if (name == nullptr || dest == nullptr || name[0] == '\0' || dest[0] == '\0' || d < 1 || d > 31 || m < 1 || m > 12 || y < 2017 || y > 2020 )
		{
			m_name[0] = '\0';
			m_destination[0] = '\0';
			m_departureYear = 0;
			m_departureDay = 0;
			m_departureMonth = 0;
		}
		else
		{
			strcpy(this->m_name, name);
			strcpy(this->m_destination, dest);
			this->m_departureDay = d;
			this->m_departureMonth = m;
			this->m_departureYear = y;
			
		}
			
	}

	// TODO: add the travelWith(...) function here
	void Passenger::travelWith(const Passenger* arrpassengers, int size) const
	{
		bool s = false;
		string fr;
		string c = ", ";
		for (int i = 0; i < size; i++)
		{
			if ((strcmp(arrpassengers[i].m_destination, this->m_destination) == 0) && arrpassengers[i].m_departureDay == this->m_departureDay && arrpassengers[i].m_departureMonth == this->m_departureMonth && arrpassengers[i].m_departureYear == this->m_departureYear)
			{
				if (i == size - 1)
				{
					fr.append(arrpassengers[i].m_name);
				}
				else
				{
					fr.append(arrpassengers[i].m_name);
					fr.append(c);
				}
				s = true;
			}
		}
		if (size == 3)
		{
			cout << "Everybody can join " << this->m_name << " on vacation!" << endl;
			cout << m_name << " will be accompanied by " << fr << "." << endl;
		}

		else if (s == false)
		{
			cout << "Nobody can join " << this->m_name << " on vacation!" << endl;
		}

		else
		{
			cout << this->m_name << " will be accompanied by " << fr << "." << endl;
		}
	}

	// TODO: add the isEmpty() function here
	bool Passenger::isEmpty() const
	{
		
		return (this->m_name[0] == '\0' && this->m_destination[0] == '\0' && this->m_departureDay == 0 && this->m_departureMonth == 0 && this->m_departureYear == 0);
		
	
		
	}
	// below is the member function already provided
	// TODO: read it and understand how it accomplishes its task
	void Passenger::display(bool nameOnly) const
	{
		if (false == this->isEmpty())
		{
			cout << this->m_name;
			if (false == nameOnly)
			{
				cout << " will travel to " << this->m_destination << ". "
					<< "The journey will start on "
					<< this->m_departureYear << "-"
					<< this->m_departureMonth << "-"
					<< this->m_departureDay
					<< "." << endl;
			}
		}
		else
		{
			cout << "Invalid passenger!" << endl;
		}
	}

}
