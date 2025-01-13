#include <iostream>
#include <iomanip>
using namespace std;

struct details { // Define a structure to store item details
    string itemID; 
    string name;
    int quantity; 
    float price;
};

// Function to store item details in an array of 'details'.
void addItem(details newItem[], int &size) { 
    int resp = 1;
    while (resp != 0 && size < 100) { // Sentinel controlled loop & the storage value (size) for item details is less than 100.
        cout << "Item ID: ";
        cin >> newItem[size].itemID; // User inputs Item ID
        if (newItem[size].itemID.empty()) {  // Check if itemID is empty
            cout << "Invalid input. Please input again " << endl;
            continue; // Retry the current iteration
        }
        
        cout << "Name: ";
        cin >> newItem[size].name; // User inputs Item name
        
        cout << "Quantity: ";
        cin >> newItem[size].quantity; // User inputs Item quantity
        while (newItem[size].quantity < 0) {  // Check if quantity is negative
            cout << "Quantity cannot be negative. Please input again: ";
            cin >> newItem[size].quantity; // User reinputs Item quantity
        }
        
        cout << "Price: $";
        cin >> newItem[size].price; // User inputs Item price
        while (newItem[size].price < 0) {  // Check if price is negative
            cout << "Price cannot be negative. Please input again: RM";
            cin >> newItem[size].price; // User reinputs Item price
        }
        
        cout << "\n--------------------------------------------------------------------";
         
        size++; // Occupies 1 storage size
        
        cout << "\nAdd more Items? "; // Asks user if they want to add more items
        cout << "(Input 1 to continue, Input 0 to return to menu)\n"; // User inputs 0 if they want to return to menu (Sentinel-Controlled loop)
        cin >> resp;
        cout << "--------------------------------------------------------------------\n\n";
    }
}

void searchItem(details newItem[], int size) { // Function to find item with structure and array as its first parameter and size as the second parameter
    cout << "Search for an Item \n";
    int choice, position = -1;                 // Ensure that no search result displayed for inexistent message rather it display an error message
    int resp = 1;                              // Declaring and initializing sentinel value to control the while loop so that the while loop execute once before checking the sentinel value again
    string searchID, searchName;
    
    while (resp != 0) {                                   // Sentinel controlled while loop, when resp equal to 0, the condition is false
        cout << endl << "Press 1 to search item by ID \t Press 2 to search item by name... ";               // Give the user choice to search by Id or Name
        cin >> choice;
    
        if (choice == 1) {                                 // Search by item ID
            cout << endl << "Enter item ID: ";
            cin >> searchID;
            cout << "\n\n";
            for (int i = 0; i < size; i++)
	    {                
                if (searchID == newItem[i].itemID) {      // Search by going through the list one by one, comparing each ID the array
                    position = i;
                    break; }                              // Item found, exit the loop
		
        } else if (choice == 2) {                          // Search by item name
            cout << endl << "Enter item name: ";
            cin >> searchName;
            for (int i = 0; i < size; i++) 
	    {
                if (searchName == newItem[i].name) {       // Search by going through the list one by one, comparing each string in the array
                    position = i;
                    break; }                               // Item found, exit the loop
		}
		
        } else {                                                        // If the user enter input other than 1 or 2.
            cout << "Invalid input. Please enter a valid input.\n";
            continue;                                                   // Go back to the line 58 that prompt an input from user until valid input are entered
        }

	    
        if (position != -1) {            //Position must be positive integers since i is declared to start with value 0 in line 65 and 76, also array only accepts positive integers as its index
            cout << "--------------------------Search result-----------------------------\n";
            cout << "ID: " << newItem[position].itemID << " | Name: " << newItem[position].name << " | Quantity: "
		 << newItem[position].quantity << " | Price: RM" << newItem[position].price << endl;                   // Print all output for the particular item one by one
            cout << "--------------------------------------------------------------------\n";
            cout << "Search more Items? ";
		position = -1;                                                                               // position is reset to default if the user wants to search for another item
            cout << "(Input 1 to continue, Input 0 to return to menu)\n";                                    // Give the user option to search again or return to the menu interface
            cin >> resp;
            cout << "--------------------------------------------------------------------\n\n";
        } else {                                                                                             // Item is not found in the array
            cout << "Item not found.\n";
            cout << "Search Items again? ";
            cout << "(Input 1 to continue, Input 0 to return to menu)\n";                                    // Give the user option to search again or return to the menu interface
            cin >> resp;
            cout << "--------------------------------------------------------------------\n\n";
        }
    }
}

void updateStock(details newItem[], int size) {
    if (size == 0) {
        cout << "No items in the inventory to update.\n";
        cout << "--------------------------------------------------------------------\n\n";
        return;
    }

    int resp = 1;
    while (resp != 0) {
        string updateId;
        cout << "Enter Item ID to update stock: ";
        cin >> updateId;
        
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (newItem[i].itemID == updateId) {
                cout << "Current Quantity: " << newItem[i].quantity << "\n";
                cout << "Enter New Quantity: ";
                int newQuantity;
                cin >> newQuantity;
                while (newQuantity < 0) {
                    cout << "Error: Quantity cannot be negative. Enter a valid quantity: ";
                    cin >> newQuantity;
                }
                newItem[i].quantity = newQuantity;
                cout << "--------------------------------------------------------------------\n";
                cout << "Stock updated!\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Item with ID " << updateId << " not found.\n";
        }
        cout << "Update stock again? ";
        cout << "(Input 1 to continue, Input 0 to return to menu)\n";
        cin >> resp;
        cout << "--------------------------------------------------------------------\n\n";
    }
}

void generateSummaryReport(details newItem[], int size) {
	int resp = 1;
    if (size == 0) {
    	while (resp != 0){
		cout << "No items in the inventory.\n";
        cout << "--------------------------------------------------------------------\n\n";
        cout << "Input 0 to return to Menu\n";
        cin >> resp;
        cout << "\n--------------------------------------------------------------------\n\n";
        return; 	
		}
    }
    else if (size > 0){
    while (resp != 0){
    double totalValue = 0.0;
    cout << "Inventory Summary Report:\n";
    cout << left << setw(5) << "ID"
         << setw(10) << "Name"
         << setw(10) << "Quantity"
         << setw(10) << "Price"
         << setw(10) << "Total Value\n";
    for (int i = 0; i < size; i++) {
        double itemValue = newItem[i].quantity * newItem[i].price;
        totalValue += itemValue;
        cout << left << setw(5) << newItem[i].itemID
             << setw(10) << newItem[i].name
             << setw(10) << newItem[i].quantity << fixed << setprecision(2)
             << setw(10) << newItem[i].price
             << setw(10) << itemValue << "\n";
    }
    cout << string(68, '-') << "\n";
    cout << "Total Inventory Value: $" << fixed << setprecision(2) << totalValue << "\n";
    cout << "--------------------------------------------------------------------\n\n";
    cout << "Input 0 to return to Menu\n";
    cin >> resp;
    cout << "\n--------------------------------------------------------------------\n\n";
}	
	}
    	
	}
// Main function to run the Inventory Tracking System
int main() {
    int choice;
    int size = 0;
    details newItem[100]; // Set the storage to 100
    do {
        cout << "Inventory Tracking System \n";
        cout << "1. Add an Item \n";
        cout << "2. Search for an Item \n";
        cout << "3. Update Stock \n";
        cout << "4. Generate Summary Report \n";
        cout << "5. Exit \n\n";
    
        cout << "Enter your choice: ";
        cin >> choice; // User inputs their choice 
        cout << "--------------------------------------------------------------------\n";
    
        switch (choice) { 
        case 1:
            addItem(newItem, size);
            break;
        case 2:
            searchItem(newItem, size);                        // call the searchItem function
            break;
        case 3:
            updateStock(newItem, size);
            break;
        case 4:
            generateSummaryReport(newItem, size);
            break;
        case 5:
            cout << "Program End \n";
            break;
        default:
            cout << "Invalid Input\n\n";
        }
    } while (choice != 5); // Program ends when user input 5 (Sentinel-Controlled loop)
    
    return 0;
}
