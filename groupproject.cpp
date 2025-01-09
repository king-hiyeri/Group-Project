#include <iostream>
#include <iomanip>

using namespace std;

struct details {
    string itemID;
    string name;
    int quantity; 
    float price;
};

void addItem(details newItem[], int &size) { // Function to store item details in an array of details.
    int resp = 1;
    while (resp != 0 && size < 100) { // Sentinel controlled loop
        cout << "Item ID: ";
        cin >> newItem[size].itemID; // User input Item ID
        if (newItem[size].itemID.empty()) {  // Check if itemID is empty
            cout << "Invalid input. Please input again " << endl;
            continue; // Retry the current iteration
        }
        
        cout << "Name: ";
        cin >> newItem[size].name;
        
        cout << "Quantity: ";
        cin >> newItem[size].quantity;
        while (newItem[size].quantity < 0) {  // Check if quantity is negative
            cout << "Quantity cannot be negative. Please input again: ";
            cin >> newItem[size].quantity;
        }
        
        cout << "Price: $";
        cin >> newItem[size].price;
        while (newItem[size].price < 0) {  // Check if price is negative
            cout << "Price cannot be negative. Please input again: RM";
            cin >> newItem[size].price;
        }
        
        cout << "\n--------------------------------------------------------------------";
         
        size++;
        
        cout << "\nAdd more Items? ";
        cout << "(Input 1 to continue, Input 0 to return to menu)\n";
        cin >> resp;
        cout << "--------------------------------------------------------------------\n\n";
    }
}

void searchItem(details newItem[], int size) {
    cout << "Search for an Item \n";
    int choice, position = -1;
    int resp = 1;
    string searchID, searchName;
    
    while (resp != 0) {
        cout << "Input 1 to search item by ID\nInput 2 to search item by name: ";
        cin >> choice;
    
        if (choice == 1) {
            cout << "Enter item ID: ";
            cin >> searchID;
            cout << "\n\n";
            for (int i = 0; i < size; i++) {
                if (searchID == newItem[i].itemID) {
                    position = i;
                    break;
                }
            }
        } else if (choice == 2) {
            cout << "Enter item name: ";
            cout << "\n\n";
            cin >> searchName;
            for (int i = 0; i < size; i++) {
                if (searchName == newItem[i].name) {
                    position = i;
                    break;
                }
            }
        } else {
            cout << "Invalid input. Please enter a valid input.\n";
            continue;
        }

        if (position != -1) {
            cout << "--------------------------Search result-----------------------------\n";
            cout << "ID: " << newItem[position].itemID << " | Name: " << newItem[position].name << " | Quantity: " << newItem[position].quantity << " | Price: RM" << newItem[position].price << endl;
            cout << "--------------------------------------------------------------------\n";
            cout << "Search more Items? ";
            cout << "(Input 1 to continue, Input 0 to return to menu)\n";
            cin >> resp;
            cout << "--------------------------------------------------------------------\n\n";
        } else {
            cout << "Item not found.\n";
            cout << "Search Items again? ";
            cout << "(Input 1 to continue, Input 0 to return to menu)\n";
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

int main() {
    int choice;
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
        cout << "--------------------------------------------------------------------\n";
    
        switch (choice) {
        case 1:
            addItem(newItem, size);
            break;
        case 2:
            searchItem(newItem, size);
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
    } while (choice != 5);
    
    return 0;
}

