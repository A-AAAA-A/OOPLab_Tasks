#include<iostream>
#include<algorithm>
using namespace std;

class Product {
private:
    int productId;
    string productName;
    int stockQuantity;

public:
    Product() {}
    Product(int id, string name, int quantity) : productId(id), productName(name), stockQuantity(quantity) {}

    void showDetails() const {
        cout << "Product ID: " << productId << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Stock Quantity: " << stockQuantity << endl;
    }

    int getId() const {
        return productId;
    }

    string getName() const {
        return productName;
    }
};

class Inventory {
private:
    Product inventory[10];
    int productCount = 0;

public:
    void addProduct(int id, string name, int quantity) {
        inventory[productCount++] = Product(id, name, quantity);
    }

    void sortInventory() {
        for (int i = 0; i < productCount; i++) {
            for (int j = i + 1; j < productCount; j++) {
                if (inventory[i].getName() > inventory[j].getName()) {
                    Product temp = inventory[i];
                    inventory[i] = inventory[j];
                    inventory[j] = temp;
                }
            }
        }
        showInventory();
    }

    void searchProduct(int id) {
        for (int i = 0; i < productCount; i++) {
            if (inventory[i].getId() == id) {
                inventory[i].showDetails();
                return;
            }
        }
        cout << "Product with ID " << id << " not found." << endl;
    }

    void showInventory() const {
        for (int i = 0; i < productCount; i++) {
            inventory[i].showDetails();
        }
    }
};

int main() {
    Inventory warehouse;

    warehouse.addProduct(103, "Arduino", 5);
    warehouse.addProduct(101, "Cable", 20);
    warehouse.addProduct(105, "Cord", 10);
    warehouse.addProduct(102, "Screen", 8);

    cout << "Inventory Display (Unsorted):\n";
    warehouse.showInventory();

    cout << "\nInventory Display (Sorted by Name):\n";
    warehouse.sortInventory();

    cout << "\nSearch Result for Product with ID 102:\n";
    warehouse.searchProduct(102);

    return 0;
}
