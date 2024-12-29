#include <iostream>
using namespace std;

int main()
{
	int choice;
	int resp = 1;
	int size = 0;
	struct details{
		string itemID;
		string name;
		int quantity;
		float price;
	};
	
	details newItem[size];
	
	do {
        cout << "Inventory Tracking System \n";
        cout << "1. Add an Item \n";
        cout << "2. Search for an Item \n";
        cout << "3. Update Stock \n";
        cout << "4. Generate Summary Report \n";
        cout << "5. Exit \n\n";
    
        cout << "Enter your choice: ";
        cin >> choice;
    
        switch (choice) {
        case 1: // J use an array of structures to store details
		  
            while (resp != 0) // Sentinel controlled loop
			{
			cout << "Item ID: ";
			cin >> newItem.itemID;
			size++;
			}
            cout << "It is finished.\n";
            cout << "----------------------------------------\n\n";
        	break;
        	
        case 2: // Thierry
        	cout << "Search for an Item \n";
        	break;
        case 3: // Luq
        	cout << "Update Stock \n";
        	break;
        case 4: // All
        	cout << "Generate Summary Report \n";
        	break;
        case 5:
        	cout << "Program End \n";
        	break;
    default:
    	cout << "Invalid Input";
	}
    } while (choice !=5);
	
    return 0;
}
