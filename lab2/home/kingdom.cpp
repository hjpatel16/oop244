// OOP244 Workshop 2: ??????????
// File ???????
// Version 1.0
// Date ???????????
// Author Harsh Patel
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// Harsh	26-1-2017	
///////////////////////////////////////////////////////////


// TODO: include the necessary headers
#include <cstring>
#include <iostream>
#include "kingdom.h"
using namespace std;

// TODO: the westeros namespace

namespace westeros
{


	// TODO:definition for display(...) 

	void display(Kingdom& pkingdoms)
	{
		cout << pkingdoms.m_name << ", population " << pkingdoms.m_population << endl;
		cout << "------------------------------" << endl;
	}
	void display(Kingdom pkingdom[], int c)
	{
		int i;
		unsigned long int tot_pop = 0;
		cout << "------------------------------" << endl
			<< "Kingdoms of Westeros" << endl
			<< "------------------------------" << endl;
		for (i = 0; i < c; i++)
		{
			cout << i + 1 << ". " << pkingdom[i].m_name << ", population " << pkingdom[i].m_population << endl;
			tot_pop = tot_pop + pkingdom[i].m_population;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of Westeros: " << tot_pop << endl;
		cout << "------------------------------" << endl;
	}

	void display(Kingdom pking[], int cp, int m)
	{
		int i;
		cout << "------------------------------" << endl;
		cout << "Kingdoms of Westeros with more than " << m << " people" << endl;
		cout << "------------------------------" << endl;
		for (i = 0; i < cp; i++)
		{
			if (pking[i].m_population >= m)
			{
				cout << pking[i].m_name << ", population " << pking[i].m_population << endl;
			}
		}
		cout << "------------------------------" << endl;
	}

	void display(Kingdom pk[], int cp, const char mname[])
	{
		int i;
		int d = 1;
		cout << "------------------------------" << endl;
		cout << "Searching for kingdom " << mname << " in Westeros" << endl;
		cout << "------------------------------" << endl;
		for (i = 0; i < cp && d == 1; i++)
		{
			if (strcmp(mname, pk[i].m_name) == 0)
			{
				d = 0;
			}
		}

		if (d == 0)
		{
			cout << pk[i-1].m_name << ", population " << pk[i-1].m_population << endl;
		}
		else
		{
			cout << mname << " is not part of Westeros." << endl;
			cout << "------------------------------" << endl << endl;
		}
	}
}


