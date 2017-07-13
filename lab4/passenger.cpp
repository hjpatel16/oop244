// TODO: add your headers here
#include <iostream>
#include<cstring>
#include "passenger.h"
// TODO: add the namespaces that you will be using here
using namespace std;
// TODO: holiday namespace here
namespace holiday
{	// TODO: add the default constructor here
	Passenger::Passenger()
	{
		m_name[0] = '\0';
		m_destination[0] = '\0';
		m_departureYear = 0;
		m_departureDay = 0;
		m_departureMonth = 0;
	}
	// TODO: add the constructor with 2 parameters here
	Passenger::Passenger(const char name[], const char dest[])
	{
		if (name == nullptr || dest == nullptr || name[0] == '\0' || dest[0] == '\0')
		{
			m_name[0] = '\0';
			m_destination[0] = '\0';
			m_departureYear = 0;
			m_departureDay = 0;
			m_departureMonth = 0;
		}
		else
		{
			this->m_departureDay = 1;
			this->m_departureMonth = 7;
			this->m_departureYear = 2017;
			strcpy(this->m_name, name);
			strcpy(this->m_destination, dest);	
		}		
	}
	// TODO: add the canTravelWith(...) function here
	bool Passenger::canTravelWith(const Passenger& a) const
	{
		bool i = false;

		if (strcmp(a.m_destination,this->m_destination) == 0 )
		{
			i = true;
		}
		return i;
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