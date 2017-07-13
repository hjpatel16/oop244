#ifndef ICT_POSAPP_H_
#define ICT_POSAPP_H_
#include <iostream>
#include"Item.h"
// ict namespace 
namespace ict {

	class PosApp
	{

		char m_filename[128];
		char m_billfname[128];
		Item* m_items[MAX_NO_ITEMS];
		int m_noOfItems;

		// methods

		int menu();
		void deallocateItems();
		void loadRecs();
		void saveRecs();
		int searchItems(const char* sku)const;
		void updateQty();
		void addItem(bool isPerishable);
		void truncateBillFile();
		void showBill();
		void listItems()const;
		void addToBill(Item& I);
		void POS();
	public:
		PosApp(const char* filename, const char* billfname); //constructor
		void run();
	};
}

#endif