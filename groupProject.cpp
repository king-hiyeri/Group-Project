#include <iostream>
using namespace std;

int main()
{
	int choice;
    cout << "Inventory Tracking System \n";
    cout << "1. Add an Item \n";
    cout << "2. Search for an Item \n";
    cout << "3. Update Stock \n";
    cout << "4. Generate Summary Report \n";
    cout << "5. Exit \n\n";
    
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice) {
    case 1: //  Thierry
    // Insert Code Block
    	cout << "Add an Item";
    	break;
    case 2: // Jeremy
    // Insert Code Block
    	cout << "Search for an Item";
    	break;
    case 3: // Luq
    // Insert Code Block
    	cout << "Update Stock";
    	break;
    case 4: // All
    // Insert Code Block
    	cout << "Generate Summary Report";
    	break;
    case 5:
    // Insert Code Block
    	cout << "Program End";
    	break;
    default:
    	cout << "Invalid Input";
	}
   

    return 0;
}
