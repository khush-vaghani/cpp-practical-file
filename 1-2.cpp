#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
private:
    int productID;
    string name;
    int quantity;
    double price;

public:
    Product(int id, string productName, int qty, double unitPrice) {
        productID = id;
        name = productName;
        quantity = qty;
        price = unitPrice;
    }

    int getProductID() const {
        return productID;
    }

    void updateQuantity(int qtyChange) {
        quantity += qtyChange;
    }

    double getValue() const {
        return quantity * price;
    }

    void display() const {
        cout << "ID: " << productID
             << " | Name: " << name
             << " | Quantity: " << quantity
             << " | Price: $" << price << endl;
    }
};

class Inventory {
private:
    vector<Product> products;

public:
    void addProduct(int id, string name, int quantity, double price) {
        
        for (const auto& product : products) {
            if (product.getProductID() == id) {
                cout << "Product with ID " << id << " already exists!" << endl;
                return;
            }
        }
        Product newProduct(id, name, quantity, price);
        products.push_back(newProduct);
        cout << "Product added successfully.\n";
    }

    void updateProductQuantity(int id, int qtyChange) {
        for (auto& product : products) {
            if (product.getProductID() == id) {
                product.updateQuantity(qtyChange);
                cout << "Product quantity updated.\n";
                return;
            }
        }
        cout << "Product with ID " << id << " not found!\n";
    }

    void displayInventory() const {
        cout << "\n--- Inventory ---\n";
        for (const auto& product : products) {
            product.display();
        }
    }

    void calculateTotalValue() const {
        double totalValue = 0;
        for (const auto& product : products) {
            totalValue += product.getValue();
        }
        cout << "Total inventory value: $" << totalValue << endl;
    }
};

int main() {
    Inventory storeInventory;

    storeInventory.addProduct(101, "Soap", 50, 1.99);
    storeInventory.addProduct(102, "Shampoo", 30, 4.49);
    storeInventory.addProduct(103, "Toothpaste", 20, 2.99);

    storeInventory.displayInventory();

    storeInventory.updateProductQuantity(101, 25);   
    storeInventory.updateProductQuantity(102, -10);  

    storeInventory.displayInventory();

    storeInventory.calculateTotalValue();

    return 0;
}
