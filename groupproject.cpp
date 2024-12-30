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
		int choice, position, searchID;
		string searchName;
		
		cout << "Press 1 to search item by ID\nPress 2 to search item by name: ";
		cin >> choice;
		
		if (choice == 1){
			cout << "Enter item ID: ";
			cin >> searchID;
			
			for (i = 0; i < size: i++)
			{
				if (searchID == newItem[i].itemID){
					position = i;
				}
			}
			
		}else if (choice == 2){
			cout << "Enter item name: ";
			cin >> searchName;
			
			for (i=0; i < size: i++)
			{
				if (searchName == newItem[i].name){
					position = i;
				}
			}
			
		}else {
			cout << "Invalid input. Please enter a valid input."
			position = -1;
		}
		
		while (position != -1){
			cout << "--------------------------Search result-----------------------------"
			cout << newItem[position].itemID << " " << newItem[position].name << " "
				 << newItem[position].quantity << " " << newItem[position].price << endl;
			break;
		}
		
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
