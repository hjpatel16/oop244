#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "NonPerishable.h"

using namespace std;

namespace ict
{
	bool NonPerishable::ok() const
	{
		return (m_err.isClear());
	}

	void NonPerishable::error(const char* message)
	{
		m_err.message(message);
	}

	 char NonPerishable::signature()const
	{
		 return 'N';
	}

	 std::fstream& NonPerishable::save(std::fstream& file)const
	 {
		 if (file.is_open())
		 {
			 file << this->signature() << "," << this->sku() << "," << this->name() << "," << this->price() << "," << int(this->taxed()) << "," << this->quantity();
		 }
		 return file;
	 }

	 std::fstream& NonPerishable::load(std::fstream& file)
	 {
		 char sku[MAX_SKU_LEN];
		 char name[100];
		 double p = 0;
		 int a;
		 char c;
		 int quantity;

		 if (file.good())
		 {
			 file.getline(sku, MAX_SKU_LEN, ',');
			 Item::sku(sku);
			 file.getline(name, 100, ',');
			 Item::name(name);
			 file >> p >> c;
			 Item::price(p);
			 file >> a >> c;
			 Item::taxed(a);
			 file >> quantity;
			 Item::quantity(quantity);
			 file.ignore();
		 }
	
		 return file;
	 }

	 ostream& NonPerishable::write(ostream& ostr, bool linear)const
	 {
		 if (this->ok())
		 {
			 if (linear)
			 {
				 ostr << std::setfill(' ') << left << std::setw(MAX_SKU_LEN)<< sku();
				 ostr << "|";
				 ostr << std::setfill(' ') << left << std::setw(20)<< name();
				 ostr << "|";
				 ostr.setf(ios::right);
				 ostr.width(7);
				 ostr.setf(ios::fixed);
				 ostr.precision(2);
				 ostr << price();
				 ostr << "|";
				 if (taxed())
				 {
					 ostr << " T" << signature();
					 ostr << "|";
				 }
				 else
				 {
					 ostr << "  " << signature();
					 ostr << "|";
				 }
				 ostr.width(4);
				 ostr << quantity();
				 ostr << "|";
				 ostr.width(9);
				 ostr.precision(2);
				 ostr << cost() * quantity();
				 ostr << "|";
			 }

			 else
			 {
				
					 ostr << "Name:" << endl;
					 ostr << name() << endl;
					 ostr << "Sku: " << sku() << endl << "Price: " << price() << endl;
					 if (taxed())
						 ostr << "Price after tax: " << (price() + price() * TAX) << endl;
					 else
						 ostr << "Price after tax: N/A" << endl;
					 ostr <<"Quantity: " << quantity() << endl << "Total Cost: " << cost() * quantity() << endl;
				
			 }
		 }
		 else
		 {
			 ostr << m_err. operator const char*();
		 }
		 return ostr;
	 }

	 std::istream& NonPerishable::read(std::istream& is)
	 {
		 char err[1000];
		 char _sku[MAX_SKU_LEN];
		 char _name[100];
		 char a[100];
		 double _price;
		 int ibuf;
		 if (is.fail())
		 {
			 return is;
		 }
		 else
		 {
			 m_err.clear();
			 cout << "Item Entry:" << endl;
			 cout << "Sku: ";
			 is >> _sku;
			 sku(_sku);
			 is.ignore();
			 cout << "Name:" << endl;
			 is >> _name;
			 name(_name);
			 is.ignore();
			 cout << "Price: ";
			 is >> _price;
			 if (is.fail())
			 {
				 strcpy(err,"Invalid Price Entry");
				 this->error(err);
				 return is;
			 }
			 else
			 {
				 price(_price);
			 }
			 is.ignore();
			 cout << "Taxed: ";
			 is >> a;
			 if (strlen(a) > 1)
			 {
				 is.setstate(ios::failbit);
				 strcpy(err, "Invalid Taxed Entry, (y)es or (n)o");
				 this->error(err);
				 return is;
			 }
			 else
			 {
				 if (a[0] == 'y'|| a[0] == 'Y')
					 taxed(true);
				 else
					 taxed(false);
			 }
			 cout << "Quantity: ";
			 is >> ibuf;
			 if (is.fail())
			 {
				 strcpy(err, "Invalid Quantity Entry");
				 this->error(err);
				 return is;
			 }
			 else
			 {
				 quantity(ibuf);
			 }
		 }

		 return is;
	 }

}