#ifndef ICT_ITEM_H__
#define ICT_ITEM_H__
// inlcude PosIO and POS header files
#include<iostream>
#include "POS.h"
#include "PosIO.h"
using namespace std;
namespace ict{
	// class Item
	class Item : public PosIO {

		char m_sku[MAX_SKU_LEN + 1];
		char* m_name;
		double m_price;
		bool m_taxed;
		int m_quantity;

	public:
		Item();
		Item(const char[], const char*, double, bool tax = true);
		Item(const Item&);
		Item& operator=(const Item&);

		//Modifiers

		void sku(const char[]);
		void name(const char*);
		void taxed(bool);
		void price(double);
		void quantity(int);

		//Queries

		const char* sku()const;
		const char* name() const;
		int quantity()const;
		double price()const;
		bool taxed()const;
		double cost()const;
		bool isEmpty()const;

		//Operator Overloads

		bool operator==(const char[]);
		int operator+=(int);
		int operator-=(int);

	};

	// end class Item
	// operator += 
	double operator+=(double& d, const Item& I);
	// operator << and operator >>
	 std::ostream& operator<<(std::ostream& ost, const Item&);
	 std::istream& operator>>(std::istream& is, Item&);
}


#endif