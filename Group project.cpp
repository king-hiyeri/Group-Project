#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    double price;
};

const int MAX_ITEMS = 100;
Item inventory[MAX_ITEMS];
int itemCount = 0;

int addItem() {
    if (itemCount >= MAX_ITEMS) {
        cout << "Inventory is full! Cannot add more items.\n";
        return -1; // Indicate failure
    }
    Item newItem;
    cout << "Enter Item ID: ";
    cin >> newItem.id;
    cout << "Enter Item Name: ";
    cin.ignore();
    getline(cin, newItem.name);
    cout << "Enter Quantity: ";
    cin >> newItem.quantity;
    while (newItem.quantity < 0) {
        cout << "Quantity cannot be negative. Enter again: ";
        cin >> newItem.quantity;
    }
    cout << "Enter Price:RM ";
    cin >> newItem.price;
    while (newItem.price < 0) {
        cout << "Price cannot be negative. Enter again: ";
        cin >> newItem.price;
    }
    inventory[itemCount++] = newItem;
    cout << "Item added successfully!\n";
    return 0;
}
int searchItem() {
    if (itemCount == 0) {
        cout << "No items in the inventory to search.\n";
        return -1; 
    }
    cout << "Search by (1) ID or (2) Name: ";
    int option;
    cin >> option;
    if (option == 1) {
        int searchId;
        cout << "Enter Item ID: ";
        cin >> searchId;
        for (int i = 0; i < itemCount; ++i) {
            if (inventory[i].id == searchId) {
                cout << "Item Found: ID=" << inventory[i].id
                     << ", Name=" << inventory[i].name
                     << ", Quantity=" << inventory[i].quantity
                     << ", Price=" << inventory[i].price << "\n";
                return i; 
            }
        }
        cout << "Item with ID " << searchId << " not found.\n";
        return -1; // Not found
    } else if (option == 2) {
        string searchName;
        cout << "Enter Item Name: ";
        cin.ignore();
        getline(cin, searchName);
        for (int i = 0; i < itemCount; ++i) {
            if (inventory[i].name == searchName) {
                cout << "Item Found: ID=" << inventory[i].id
                     << ", Name=" << inventory[i].name
                     << ", Quantity=" << inventory[i].quantity
                     << ", Price=" << inventory[i].price << "\n";
                return i; 
            }
        }
        cout << "Item with Name \"" << searchName << "\" not found.\n";
        return -1; 
    } else {
        cout << "Invalid option. Returning to menu.\n";
        return -1; 
    }
}


int updateStock() {
    if (itemCount == 0) {
        cout << "No items in the inventory to update.\n";
        return -1;
    }
    int updateId;
    cout << "Enter Item ID to update stock: ";
    cin >> updateId;
    for (int i = 0; i < itemCount; ++i) {
        if (inventory[i].id == updateId) {
            cout << "Current Quantity: " << inventory[i].quantity << "\n";
            cout << "Enter New Quantity: ";
            int newQuantity;
            cin >> newQuantity;
            while (newQuantity < 0) {
                cout << "Error: ";
                cin >> newQuantity;
            }
            inventory[i].quantity = newQuantity;
            cout << "Stock updated!\n";
            return 0;
        }
    }
    cout << "Item with ID " << updateId << " Error.\n";
    return -1; 
}

// Function to generate summary report
double generateSummaryReport() {
    if (itemCount == 0) {
        cout << "No items in the inventory .\n";
        return 0.0; 
    }
    double totalValue = 0.0;
    cout << "Inventory Summary Report:" << "\n";
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Quantity"
         << setw(10) << "Price"
         << setw(15) << "Total Value\n";
    for (int i = 0; i < itemCount; i++) {
        double itemValue = inventory[i].quantity * inventory[i].price;
        totalValue += itemValue;
        cout << left << setw(10) << inventory[i].id
             << setw(20) << inventory[i].name
             << setw(10) << inventory[i].quantity
             << setw(10) << inventory[i].price
             << setw(15) << itemValue << "\n";
    }
    cout << string(65, '-') << "\n";
    cout << "Total Inventory Value: RM " << totalValue << "\n";
    return totalValue; 
}

int main() {
    int choice;
    do {
        cout << "\nInventory Tracking System \n";
        cout << "1. Add an Item \n";
        cout << "2. Search for an Item \n";
        cout << "3. Update Stock \n";
        cout << "4. Generate Summary Report \n";
        cout << "5. Exit \n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addItem();
            break;
        case 2:
            searchItem();
            break;
        case 3:
            updateStock();
            break;
        case 4:
            generateSummaryReport();
            break;
        case 5:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
