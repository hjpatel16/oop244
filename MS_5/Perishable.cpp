#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iostream>
#include<cstring>
#include "Perishable.h"

using namespace std;

namespace ict
{
	Perishable::Perishable()
	{
		m_expiry.dateOnly(true);
	}

	std::fstream& Perishable::save(std::fstream& file)const
	{
		NonPerishable::save(file);
		file << "," << m_expiry;
		return file;
	}

	std::fstream& Perishable::load(std::fstream& file)
	{
		NonPerishable::load(file);
		file.ignore();
		file >> m_expiry;
		return file;
	}

	std::ostream& Perishable::write(std::ostream& ostr, bool linear) const 
	{

		NonPerishable::write(ostr, linear);
		if (linear == false && ok()) {

			ostr << "Expiry date: " << m_expiry << endl;

		}
		return ostr;
	}

	std::istream& Perishable::read(std::istream& is)
	{
		cout << "Perishable ";
		NonPerishable::read(is);
		if (is.fail())
		{
			return is;
		}
		m_expiry.errCode(0);
		cout << "Expiry date (YYYY/MM/DD): ";
		is >> m_expiry;

		if (m_expiry.errCode() == CIN_FAILED)
		{
			error("Invalid Date Entry");
			is.setstate(ios::failbit);
		}
		if (m_expiry.errCode() == YEAR_ERROR)
			{
				error("Invalid Year in Date Entry");
				is.setstate(ios::failbit);
			}
		if (m_expiry.errCode() == MON_ERROR)
			{
				error("Invalid Month in Date Entry");
				is.setstate(ios::failbit);
			}
		if (m_expiry.errCode() == DAY_ERROR)
			{
				error("Invalid Day in Date Entry");
				is.setstate(ios::failbit);
			}
	
		return is;
	}


}
