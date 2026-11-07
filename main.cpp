#include <iostream>

// Chapter 19, Programming Challenge 12: Inventory Bin Queue
#include <iostream>
#include <iomanip>
#include "InvItem.h"
#include "InvStack.h"
#include "InvQue.h"

using namespace std;

template <class Container>
void displayInventory(const Container &inventory)
{
	int count = 0;

	cout << "\n" << left << setw(6) << "#" << setw(16) << "Serial Number"
		 << "Manufacture Date\n";
	cout << string(40, '-') << endl;

	inventory.forEach([&count](const InventoryItem &item)
	{
		count++;
		cout << left << setw(6) << count << setw(16) << item.getSerialNum()
			 << item.getManufactDate() << endl;
	});

	if (count == 0)
		cout << "The inventory is empty.\n";
}

int main()
{
	InvStack<InventoryItem> stack;	// create stack
	InvQue<InventoryItem> queue; // create queue
	InventoryItem item;				// create inventory item object

	int choice;						// Menu choice
	long serial;					// Serial number
	string mDate;					// Manufacture date
	int structure;
	bool useQueue;

	cout << "Store inventory in a:\n1.  Queue\n2.  Stack\n\nChoice (1 or 2):  ";
	cin >> structure;
	while (structure < 1 || structure > 2)
	{
		cout << "Please enter 1 or 2: ";
		cin >> structure;
	}
	useQueue = (structure == 1);
	
	do
	{
		// Display the menu.
		cout << "\n------ Inventory Menu --------\n\n";
		cout << "1.  Enter a part into the inventory.\n";
		cout << "2.  Take a part from the inventory.\n";
		cout << "3.  Quit.\n";
		cout << "4.  Display all parts.\n\n";
		cout << "Please make a choice (1, 2, 3, or 4):  ";
		cin >> choice;

		// Validate choice
		while (choice < 1 || choice > 4)
		{
			cout << "Please enter 1, 2, or 3, or 4: ";
			cin >> choice;
		}

		// Act on the user's choice.
		switch(choice)
		{

		case 1:
			// Enter a part into inventory.
			cout << "\nYou have chosen to add an item to the inventory bin.\n\n";
			cout << "Enter the item's serial number: ";
			cin >> serial;
			item.setSerialNum(serial);
			cout << "Enter the item's manufacture date: ";
			cin >> mDate;
			item.setManufactDate(mDate);
			if (useQueue)
				queue.enqueue(item);
			else
				stack.push(item);
			break;

		case 2: 
			// Take a part out of inventory.
			cout << "\nYou have chosen to remove an item from the inventory bin.\n\n";
						if ((useQueue && queue.isEmpty()) || (!useQueue && stack.isEmpty()))
				cout << "No parts to remove.\n";
			else
			{
				if (useQueue)
					queue.dequeue(item);
				else
					stack.pop(item);
				cout << "\nThe part you removed was:\n";
				cout << "\tSerial number: " << item.getSerialNum() << endl;
				cout << "\tManufacture date: " << item.getManufactDate() << endl;
				cout << endl;
			}
			break;

		case 3:
			cout << "\nGoodbye!\n\n";
			break;

		case 4:
			if (useQueue)
				displayInventory(queue);
			else
				displayInventory(stack);
			break;
		}
	} while (choice  != 3);

	return 0;
}