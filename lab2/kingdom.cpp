// OOP244 Workshop ??: ??????????
// File ???????
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////


// TODO: include the necessary headers

#include<iostream>
#include "kingdom.h"
using namespace std;

// TODO: the westeros namespace

namespace westeros
{

	// TODO:definition for display(...) 

	void display(Kingdom& pkingdoms)
	{
		cout << pkingdoms.m_name << ", population " << pkingdoms.m_population << endl;
	}
}


