#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "PosApp.h"
#include "NonPerishable.h"
#include "Perishable.h"
using namespace std;

namespace ict
{
	PosApp::PosApp(const char* filename, const char* billfname)
	{
		strncpy(this->m_filename, filename, 128);
		strncpy(this->m_billfname, billfname, 128);
	}

	int PosApp::menu()
	{
		int a;
		cout << "The Sene-Store " << endl << "1- List items" << endl << "2- Add Perishable item" << endl
			<< "3- Add Non-Perishable item" << endl << "4- Update item quantity" << endl << "5- Show Item"
			<< endl << "6- POS" << endl << "0- exit program" << endl << "> ";
		cin >> a;
		cout << endl;
		cin.ignore(2000, '\n');
		return a;
	}

	void PosApp::deallocateItems()
	{
		for (int i = 0; i < m_noOfItems; i++)
		{
			delete[] m_items[i];
			m_items[i] = (Item*)0;
		}
		this->m_noOfItems = 0;
	}

	void PosApp::loadRecs()
	{
		int index = 0;
		this->deallocateItems();
		fstream npfile(this->m_filename, ios::in);
		if (npfile.fail())
		{
			npfile.clear();
			npfile.close();
			fstream npfile(this->m_filename, ios::out);
			npfile.close();
		}
		
		else
		{
				while (!npfile.eof() && index < MAX_NO_ITEMS)
				{
					npfile.clear();
					char id = npfile.get();
					if (id == 'N')
					{
						m_items[index] = new NonPerishable();
						npfile.ignore(1);
						m_items[index]->load(npfile);
						index++;
					}
					if (id == 'P')
					{
						m_items[index] = new Perishable();
						npfile.ignore(1);
						m_items[index]->load(npfile);
						npfile.ignore(1);
						index++;
					}
				}
		}
		m_noOfItems = index;
		npfile.close();
	}

	
		
	void PosApp::saveRecs()
	{
		fstream f(this->m_filename, ios::out);
		
		for (int i = 0; i < this->m_noOfItems; i++)
		{
			if (m_items[i]->quantity() > 0)
			{
				m_items[i]->save(f);
				f << endl;
			}
		}
		f.close();
		this->loadRecs();
	}

	int PosApp::searchItems(const char* sku)const
	{
		int  i = 0;
			for (i = 0; i < m_noOfItems; i++)
			{
				if (*m_items[i] == sku)
				{
					return i;
				}
			}
			return -1;
	}

	void PosApp::updateQty()
	{
		int quantity;
		char sku[MAX_SKU_LEN];
		cout << "Please enter the SKU: ";
		cin >> sku;
		int i = this->searchItems(sku);
		if (i == -1)
		{
			cout << "Not found!" << endl;
		}
		else
		{
			m_items[i]->write(cout ,false);
			cout << endl << "Please enter the number of purchased items: ";
			cin >> quantity;
			*m_items[i] += quantity;
			this->saveRecs();
			cout << "Updated!" << endl << endl;
		}
	}

	void PosApp::addItem(bool isPerishable)
	{
		if (isPerishable)
		{
			Perishable* a = new Perishable;
			 a->read(cin);

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(2000, '\n');
				a->write(cout, false);
				cout << endl;
			}

			else
			{
				fstream f(m_filename, ios::out | ios::app);
				
				a->save(f);
				f.close();
				m_items[m_noOfItems] = a;
				this->m_noOfItems++;
				cout << "Item Added." << endl << endl;
			}
		}
		else
		{
			NonPerishable *a = new NonPerishable;
			a->read(cin);

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(2000, '\n');
				a->write(cout, false);
			}

			else
			{
				fstream f(m_filename, ios::out | ios::app);
			
				a->save(f);
				f.close();
				m_items[m_noOfItems] = a;
				this->m_noOfItems++;
				cout << "Item Added." << endl << endl;
			}
		}
		loadRecs();
	}
	void PosApp::listItems()const
	{
		cin.clear();
		double total = 0;
		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
		cout << "-----|--------|--------------------|-------|---|----|---------|" << endl;
		for (int i = 0; i < m_noOfItems; i++)
		{
			if (!m_items[i]->isEmpty())
			{
				cout.width(4);
				cout << i + 1 << " | ";
				m_items[i]->write(cout, true);
				total += m_items[i]->cost() * m_items[i]->quantity();
				cout << endl;
			}
		}
		cout << "-----^--------^--------------------^-------^---^----^---------^" << endl;
		cout << "                               Total Asset: $  |";
		cout << setw(14) << setprecision(2) << total;
		cout << "|" << endl;
		cout << "-----------------------------------------------^--------------^" << endl;
	}

	void PosApp::truncateBillFile()
	{
		fstream f(this->m_billfname, ios::out | ios::trunc);
		f.close();
	}

	void PosApp::showBill()
	{
		int index = 0;
		double total = 0;
		Item* items;
		fstream npfile(this->m_billfname, ios::in);
		cout << "v-------------------------------------------------------v" << endl;
		cout << "| " << Date() << setfill(' ') << setw(38) << "|" << endl;
		cout << "| SKU   | Item Name          | Price |TX |Qty |   Total |" << endl;
		cout << "|-------|--------------------|-------|---|----|---------|" << endl;
		while (npfile.good())
		{
			char id = npfile.get();
			if (id == 'N')
			{
				items = new NonPerishable();
				npfile.ignore(1);
				items->load(npfile);
				cout << "|";
				items->write(cout, true);
				total += items->cost() * items->quantity();
				delete items;
			//	npfile.ignore();
				index++;
				cout << endl;
			}
			else
			{
				items = new Perishable();
				items->load(npfile);
				cout << "|";
				items->write(cout, true);
				total += items->cost() * items->quantity();
				delete items;
				npfile.ignore();
				index++;
				cout << endl;
			}
			
		}
		cout << "^--------^--------------------^-------^---^----^--------^" << endl;
		cout << "|                               Total: $  |";
		cout.width(13);
		cout.precision(2);
		cout << total;
		cout << "|" << endl;
		cout << "^-----------------------------------------^-------------^" << endl;
		npfile.close();
		truncateBillFile();
	}
	

	void PosApp::addToBill(Item& I)
	{
		int q = I.quantity();
		I.quantity(1);
		fstream f;
		f.open(this->m_billfname, ios::out | ios::app);
		I.save(f);
		I.quantity(q - 1);
		saveRecs();
		f.close();
	}

	void PosApp::POS()
	{
		truncateBillFile();
		char* sku = new char[50];
		int index;
		while (true)
		{
			cout << "Sku: ";
			cin.getline(sku, MAX_SKU_LEN, '\n');
			index = searchItems(sku);
			if (sku[0] == '\0')
			{
				showBill();
				break;
			}
			else if (index != -1)
			{
				cout << "v------------------->" << endl;
				cout << "| " << m_items[index]->name() << endl;
				cout << "^------------------->" << endl;
				addToBill(*(m_items[index]));
			}
			else if (index == -1)
			{
				cout << "Not found!" << endl;
			}
		}
		delete[] sku;
	}



	void PosApp::run()
	{
		int j = 1;
		int i = 0;
		loadRecs();
		while (j != 0)
		{
			int a = this->menu();
			switch (a)
			{
			case 1: this->listItems();
				break;
			case 2: this->addItem(true);
				break;
			case 3: this->addItem(false);
				break;
			case 4: this->updateQty();
				break;
			case 5: 
				char sku[MAX_SKU_LEN];
				cout << "Please enter the SKU: ";
				cin >> sku;
				 i = this->searchItems(sku);
				if (i == -1)
				{
					cout << "Not found!" << endl;
				}
				else
				{
					cout << "v-----------------------------------v" << endl;
					m_items[i]->write(cout, false);
					cout << "v-----------------------------------v" << endl << endl;
				}
				break;
			case 6: 
				POS();
				break;
			case 0: cout << "Goodbye!" << endl;
				j = 0;
				break;
			default: cout << "=== Invalid Selection, try again ===" << endl;
				break;
			}
		}
	}
}
/*
ouputs:
-------------------------------------
update:
Please enter the SKU: 1313
Name:
Paper Tissue
Sku: 1313
Price: 1.22
Price after tax: 1.38
Quantity: 194
Total Cost: 267.45

Please enter the number of purchased items: 12
Updated!

------------------------------
Please enter the SKU: 3434
Not found!

-------------------------------------
add item:
Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 1200/10/12
Invalid Year in Date Entry

Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 2017/5/15
Item added.

--------------------------------------------
list item:
 Row | SKU    | Item Name          | Price |TX |Qty |   Total |
-----|--------|--------------------|-------|---|----|---------|
   1 | 1234   |Milk                |   3.99|  P|   2|     7.98|
   2 | 3456   |Paper Cups          |   5.99| TN|  38|   257.21|
   3 | 4567   |Butter              |   4.56| TP|   9|    46.38|
   4 | 1212   |Salted Butter       |   5.99|  P| 111|   664.89|
   5 | 1313   |Paper Tissue        |   1.22| TN| 206|   283.99|
   6 | 5656   |Honey               |  12.99| TP|  12|   176.14|
-----^--------^--------------------^-------^---^----^---------^
                               Total Asset: $  |       1436.59|
-----------------------------------------------^--------------^


--------------------------------------
printbill:
v--------------------------------------------------------v
| 2017/04/02, 12:42                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         22.05|
^-----------------------------------------^--------------^

-------------------------------------------------------
POS:
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1313
v------------------->
| Paper Tissue
^------------------->
Sku: 1234
v------------------->
| Milk
^------------------->
Sku: 7654
Not found!
Sku: 5656
v------------------->
| Honey
^------------------->
Sku:
v--------------------------------------------------------v
| 2017/04/02, 12:58                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 1234   |Milk                |   3.99|  P|   1|     3.99|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         32.03|
^-----------------------------------------^--------------^

------------------------------------------------------
run:
The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 5656
v-----------------------------------v
Name:
Honey
Sku: 5656
Price: 12.99
Price after tax: 14.68
Quantity: 10
Total Cost: 146.79
Expiry date: 2017/05/15
^-----------------------------------^

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 12345
Not found!

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> five

===Invalid Selection, try again===

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 0

Goodbye!

*/