#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to represent a transaction
struct Transaction {
    string date;
    string type;
    double amount;
    string description;
};

// Function to add a transaction
void addTransaction(vector<Transaction> &transactions) {
    Transaction transaction;
    cout << "Enter the date (YYYY-MM-DD): ";
    cin >> transaction.date;
    cout << "Enter the type of transaction (expense/income): ";
    cin >> transaction.type;
    cout << "Enter the amount: ";
    cin >> transaction.amount;
    cout << "Enter the description: ";
    cin.ignore(); // Ignore the newline character
    getline(cin, transaction.description);
    transactions.push_back(transaction);
    cout << "Transaction added successfully!\n";
}

// Function to display all transactions
void displayTransactions(const vector<Transaction> &transactions) {
    cout << "\n----- Transactions -----\n";
    cout << setw(12) << "Date" << setw(10) << "Type" << setw(10) << "Amount" << setw(20) << "Description" << endl;
    for (const Transaction &transaction : transactions) {
        cout << setw(12) << transaction.date << setw(10) << transaction.type << setw(10) << transaction.amount << setw(20) << transaction.description << endl;
    }
    cout << "-------------------------\n";
}

// Function to save transactions to a file
void saveTransactions(const vector<Transaction> &transactions, const string &fileName) {
    ofstream file(fileName); // Open the file in truncation mode (overwrite existing content)
    if (file.is_open()) {
        for (const Transaction &transaction : transactions) {
            file << transaction.date << " " << transaction.type << " " << transaction.amount << " " << transaction.description << endl;
            if (!file) {
                cerr << "Error writing to file '" << fileName << "'. Aborting save operation.\n";
                return;
            }
        }
        file.close();
        cout << "Transactions have been saved to the file '" << fileName << "'\n";
    } else {
        cout << "Error: Could not open the file for writing.\n";
    }
}

// Function to load transactions from a file
void loadTransactions(vector<Transaction> &transactions, const string &fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        transactions.clear(); // Clear existing transactions
        string date, type, description;
        double amount;
        while (file >> date >> type >> amount) {
            getline(file >> ws, description);
            transactions.push_back({date, type, amount, description});
        }
        file.close();
        cout << "Transactions have been loaded from the file '" << fileName << "'\n";
    } else {
        cout << "Warning: Could not open the file for reading. The file does not exist or does not have read permissions.\n";
    }
}

int main() {
    vector<Transaction> transactions;
    int option;

    string fileName = "transactions.txt";
    ofstream file(fileName); // Create the file if it doesn't exist
    file.close();

    loadTransactions(transactions, fileName); // Load existing transactions from file

    do {
        // Display menu options
        cout << "\n----- Personal Expense Management -----\n";
        cout << "1. Add transaction\n";
        cout << "2. Display transactions\n";
        cout << "3. Save transactions\n";
        cout << "0. Exit\n";
        cout << "Enter your option: ";
        cin >> option;

        cin.ignore(); // Clear any remaining characters in the input buffer

        // Perform action based on user's option
        switch (option) {
            case 1:
                addTransaction(transactions); // Add a new transaction
                break;
            case 2:
                displayTransactions(transactions); // Display all transactions
                break;
            case 3:
                saveTransactions(transactions, fileName); // Save transactions to file
                break;
            case 0:
                cout << "Goodbye!\n";
                saveTransactions(transactions, fileName); // Save transactions before exiting
                break;
            default:
                cout << "Invalid option! Please re-enter your option.\n";
        }
    } while (option != 0);

    return 0;
}
