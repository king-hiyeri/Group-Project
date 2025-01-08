#include <iostream>
using namespace std;

struct details{
		int itemID;
		string name;
		int quantity;
		float price;
	};
	
int main()
{
	int choice;
	int resp = 1;
	int size = 0;

	details newItem[100];
	
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
		  
            while (resp != 0 && size < 100){ // Sentinel controlled loop
			cout << "Item ID: ";
			cin >> newItem[size].itemID;
			if (newItem[size].itemID <= 0 ){
			   cout << "Invalid input. Please input again " << endl;
			   cin >> resp;		
			}
			
			
			cout << "Name: ";
			cin >> newItem[size].name;
			
			cout << "Quantity: ";
			cin >> newItem[size].quantity;
			
			cout << "Price: RM";
			cin >> newItem[size].price;
			 
			size++;
			
            cout << "Add more Items?\n";
            cout << "(Input 1 to continue, Input 0 to Exit)\n";
            cin >> resp;
            cout << "\n****************************************************************************************\n";
        }
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
