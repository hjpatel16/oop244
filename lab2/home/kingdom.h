// OOP244 Workshop 2: ??????????
// File ???????
// Version 1.0
// Date ???????????
// Author Harsh patel
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// Harsh patel
///////////////////////////////////////////////////////////


// TODO: header safeguards
#ifndef KINGDOM_H
#define KINGDOM_H



// TODO: westeros namespace
namespace westeros
{

	// TODO: define the class Kingdom in the westeros namespace
	class Kingdom {

	public:
		char m_name[32];
		int  m_population;

	};

	// TODO: add the declaration for the function display(...),
	//         also in the westeros namespace
	void display(Kingdom&);
	void display(Kingdom[], int);
	void display(Kingdom[], int, int);
	void display(Kingdom[], int, const char[]);
}
#endif