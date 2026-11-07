// Specification file for the InvItem class
#ifndef INVITEM_H
#define INVITEM_H
#include <string>
using namespace std;

class InventoryItem
{
private:
	long serialNum;			// Serial number
	string manufactDate;	// Manufacture date
	int lotNum;				// Lot number

public:
	// Default constructor
	InventoryItem()
		{ serialNum = 0; manufactDate = ""; lotNum = 0; }

	// Constructor
	InventoryItem(long s, string m, int lot)
		{ serialNum = s; manufactDate = m; lotNum = lot; }

	void setSerialNum(long s)
		{ serialNum = s; }

	void setManufactDate(string m)
		{ manufactDate = m; }

	void setLotNum(int lot)
		{ lotNum = lot; }

	long getSerialNum() const
		{ return serialNum; }

	string getManufactDate()
		{ return manufactDate; }

	int getLotNum() const
		{ return lotNum; }
};

#endif