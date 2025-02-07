#include<iostream>
using namespace std;

struct InventoryItem {
    int productID;
    string name;
    int quantity;
    float price;
};

void gatherProductData(InventoryItem *items, int count) {
    for(int i = 0; i < count; i++) {
        cout << "Details for Product " << i + 1 << endl;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, items[i].name);
        cout << "Enter product ID: ";
        cin >> items[i].productID;
        cout << "Enter quantity: ";
        cin >> items[i].quantity;
        cout << "Enter price: ";
        cin >> items[i].price;
    }
}

void displayInventory(InventoryItem *items, int count) {
    float totalValue = 0.0;
    for(int i = 0; i < count; i++) {
        cout << "Product " << i + 1 << " Details:" << endl;
        cout << "Name: " << items[i].name << endl;
        cout << "Product ID: " << items[i].productID << endl;
        cout << "Quantity: " << items[i].quantity << endl;
        cout << "Price per unit: $" << items[i].price << endl;
        float productValue = items[i].quantity * items[i].price;
        cout << "Total Value: $" << productValue << endl;
        totalValue += productValue;
    }
    cout << "Total Inventory Value: $" << totalValue << endl;
}

int main() {
    int numProducts;
    cout << "Enter the number of products to register: ";
    cin >> numProducts;

    InventoryItem* productArray = new InventoryItem[numProducts];

    gatherProductData(productArray, numProducts);
    displayInventory(productArray, numProducts);

    delete[] productArray;
    return 0;
}
