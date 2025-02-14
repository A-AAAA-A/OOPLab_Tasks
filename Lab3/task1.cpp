#include <iostream>
#include <string>

using namespace std;

class Wallet {
private:
    string ownerName;
    double totalBalance;
    string transactionHistory[100]; 
    int transactionCount; 

public:
    Wallet(string name) {
        ownerName = name;
        totalBalance = 0;
        transactionCount = 0;
    }

    void addMoney(double amount) {
        totalBalance += amount;
        transactionHistory[transactionCount++] = "Added: " + to_string(amount);
        cout << "Added " << amount << " to your wallet. Total balance: " << totalBalance << endl;
    }

    void spendMoney(double amount) {
        if (amount <= totalBalance) {
            totalBalance -= amount;
            transactionHistory[transactionCount++] = "Spent: " + to_string(amount);
            cout << "Spent " << amount << ". Total balance: " << totalBalance << endl;
        } else {
            cout << "Insufficient funds. Cannot spend " << amount << endl;
        }
    }

    void displayTransactionHistory() {
        cout << "Transaction History for " << ownerName << ":" << endl;
        for (int i = 0; i < transactionCount; ++i) {
            cout << transactionHistory[i] << endl;
        }
    }

    double checkBalance() {
        return totalBalance;
    }
};

int main() {
    Wallet saadWallet("Saad");

    saadWallet.addMoney(1000.50);
    saadWallet.addMoney(500.75);

    saadWallet.spendMoney(300.00);
    saadWallet.spendMoney(150.50);

    saadWallet.displayTransactionHistory();

    cout << "Final Balance: " << saadWallet.checkBalance() << endl;

    return 0;
}
