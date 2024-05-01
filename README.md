# Budget Tracker using C++

Budget Tracker is a simple C++ application for personal expense management. It allows users to track their expenses, income, and transactions conveniently.

## Features

- Add new transactions (expenses/income) with date, type, amount, and description.
- Display all transactions in a formatted list.
- Save transactions to a file for future reference.
## Dependencies

- C++ compiler (e.g., g++, clang++)
- Standard Template Library (STL)
## Getting Started

To get started with Budget Tracker, follow these steps:

1. Clone the repository to your local machine https://github.com/MihaiPopescu31/Budget-Tracker-Aplication.git
2. Compile the source code files using a C++ compiler.

3. Run the executable file generated to launch the Budget Tracker application.

## Usage

- When the application starts, you will be presented with a menu to add transactions, display transactions, save transactions, or exit the application.
- ![image](https://github.com/MihaiPopescu31/Budget-Tracker-Aplication/assets/138394009/b8976d63-3998-416f-ad6c-770c69401a3d)
- To add a transaction, choose option 1 and follow the prompts to enter the transaction details.
- To display all transactions, choose option 2. This will show a formatted list of all transactions entered.
- To save transactions to a file, choose option 3. Transactions will be saved to a file named `transactions.txt`.
- ![image](https://github.com/MihaiPopescu31/Budget-Tracker-Aplication/assets/138394009/aeea36ed-f365-4213-ad93-f5b9ed236e40)
- To exit the application, choose option 0.
  
## Code Explanation
In this section, we'll walk through the code step by step to understand how the Budget Tracker application works.

### Function addTransaction()
This function allows users to add a new transaction to the Budget Tracker. It prompts the user to enter the transaction details, including the date, type (expense/income), amount, and description. The transaction is then added to the vector of transactions.

### Function displayTransactions()
When called, this function displays all transactions stored in the vector in a formatted list. It prints out each transaction's date, type, amount, and description in a clear and readable format.

### Function saveTransactions()
The saveTransactions() function is responsible for saving all transactions to a text file named transactions.txt. It iterates through the vector of transactions and writes each transaction's details to the file in a structured format.

### Function loadTransactions()
This function is called when the application starts to load transactions from the transactions.txt file into the vector. It reads each line from the file, parses the transaction details, and adds them to the vector.

### Handling User Input
The application handles user input using the cin stream for reading input from the console. Input validation is performed to ensure that the user enters valid data for each transaction.

### File Input/Output
File input/output operations are used to save and load transactions from the transactions.txt file. The file is opened for writing in saveTransactions() and for reading in loadTransactions().

### Error Handling
Error messages are displayed to the user in case of any failures during file input/output operations or invalid user input. This ensures that the application behaves gracefully even in the presence of errors.

## Find a bug
If you found an issue or would like to submit an improvement to this project, please contact me.
