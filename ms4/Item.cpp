#define _CRT_SECURE_NO_WARNINGS  
// Lib includes
#include<iostream>
#include<cstring>
// inlcude Item and POS header files
#include "Item.h"
#include "POS.h"
using namespace std;
namespace ict{
	// class Item implementaion

	Item::Item()
	{
		this->m_name = nullptr;
		this->m_sku[0] = '\0';
		this->m_price = 0;
		this->m_quantity = 0;
	}

	Item::Item(const char sku[], const char* name, double price, bool tax)
	{
		strncpy(this->m_sku, sku, MAX_SKU_LEN);
		this->m_name = new char[strlen(name)];
		strcpy(this->m_name, name);
		this->m_quantity = 0;
		this->m_price = price;
		this->m_taxed = tax;
	}

	Item::Item(const Item& I)
	{
		this->m_taxed = I.m_taxed;
		this->m_quantity = I.m_quantity;
		this->m_price = I.m_price;
		strncpy(this->m_sku, I.m_sku, MAX_SKU_LEN);

		if (I.m_name != nullptr)
		{
			this->m_name = new char[strlen(I.m_name)];
			strcpy(this->m_name, I.m_name);
		}
	}

	Item& Item::operator=(const Item& I)
	{
		if (this != &I)
		{
			if (!I.isEmpty())
			{
				this->m_taxed = I.m_taxed;
				this->m_quantity = I.m_quantity;
				this->m_price = I.m_price;
				strncpy(this->m_sku, I.m_sku, MAX_SKU_LEN);
				
				if (I.m_name != nullptr)
				{
					this->m_name = new char[strlen(I.m_name)];
					strcpy(this->m_name, I.m_name);
				}
			}
			
		}
		return *this;
	}

	void Item::sku(const char sku[])
	{
		strncpy(this->m_sku, sku, MAX_SKU_LEN);
	}

	void Item::name(const char* name)
	{
		this->m_name = new char[strlen(name)];
		strcpy(this->m_name, name);
	}

	void Item::price(double price)
	{
		this->m_price = price;
	}

	void Item::quantity(int quantity)
	{
		this->m_quantity = quantity;
	}

	void Item::taxed(bool tax)
	{
		this->m_taxed = tax;
	}

	const char* Item::sku()const
	{
		return m_sku;
	}

	const char* Item::name() const
	{
		return m_name;
	}

	int Item::quantity()const
	{
		return m_quantity;
	}

	double Item::price()const
	{
		return m_price;
	}

	bool Item::taxed()const
	{
		return m_taxed;
	}

	double Item::cost()const
	{
		double cost;
		if (this->m_taxed)
		{
			cost = this->m_price + this->m_price*TAX;
		}
		else
		{
			cost = this->m_price;
		}
		return cost;
	}

	bool Item::isEmpty()const
	{
		return (this->m_price == 0 && this->m_quantity == 0 && this->m_sku[0] == '\0');
	}

	bool Item::operator==(const char name[])
	{
		bool i = false;
		int j = strcmp(this->m_sku, name);
		if (j == 0)
		{
			i = true;
		}
		return i;
	}

	int Item::operator+=(int quantity)
	{
		 this->m_quantity += quantity;
		return this->m_quantity;
	}

	int Item::operator-=(int quantity)
	{
		return (this->m_quantity -= quantity);
	 
	}

	double operator+=(double& d, const Item& I)
	{
		double p = I.cost() * I.quantity();
		return d += p;
	}

	std::ostream& operator<<(ostream& ost, const Item& I)
	{
		I.write(ost, true);
		return ost;
	}

	std::istream& operator>>(istream& is,  Item& I)
	{
		I.read(is);
		return is;
	}
}