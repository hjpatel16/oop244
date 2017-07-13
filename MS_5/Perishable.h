#ifndef ICT_PERISHABLE_H__
#define ICT_PERISHABLE_H__
#include<iostream>
#include "NonPerishable.h"
#include "Date.h"
using namespace std;

namespace ict
{
	class Perishable :public NonPerishable
	{
		Date m_expiry;
	protected:
		char signature()const { return 'P'; };

	public:
		Perishable();
		std::fstream& save(std::fstream& file)const;
		std::fstream& load(std::fstream& file);
		ostream& write(ostream& ostr, bool linear)const;
		std::istream& read(std::istream& is);
	};

}


#endif
