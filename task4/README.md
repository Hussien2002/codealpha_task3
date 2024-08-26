



# Banking System

## Overview

The **Banking System** is a C++ application designed with an object-oriented approach to manage customers, accounts, and transactions. The system allows users to create and manage customer accounts, perform transactions such as deposits and withdrawals, and view account information and transaction history.

## Features

- **Customer Management**: Create and manage customer profiles.
- **Account Management**: Create and manage accounts with various account types.
- **Transaction Handling**: Perform deposits, withdrawals, and view transaction history.
- **Balance Management**: Check and update account balances.

## Classes

### `transaction`
Represents a financial transaction.

- **Attributes**:
  - `trnsactionid`: Unique identifier for the transaction.
  - `type`: Type of transaction (e.g., Deposit, Withdraw).
  - `date`: Date of the transaction.
  - `amount`: Amount involved in the transaction.
  
- **Methods**:
  - Constructors (parameterized and default).
  - Setters and getters for transaction attributes.
  - `transdisplay()`: Displays transaction details.

### `account`
Represents a bank account.

- **Attributes**:
  - `account_number`: Unique account number.
  - `balance`: Current balance of the account.
  - `account_type`: Type of the account (e.g., Checking, Savings).
  - `TRANSACTION`: Vector storing transactions related to this account.
  
- **Methods**:
  - Constructors (parameterized and default).
  - `deposit(double amount)`: Deposits an amount into the account.
  - `withdraw(double amount)`: Withdraws an amount from the account.
  - `getaccountnumber()`, `getbalance()`, `getaccounttype()`: Get account details.
  - `getTransactions()`: Retrieves the list of transactions.
  - `displayTransactions()`: Displays the transaction history.

### `customer`
Represents a bank customer.

- **Attributes**:
  - `name`: Customer's name.
  - `id`: Customer's ID.
  - `contact_info`: Customer's contact information.
  - `Account`: The customer's account.
  
- **Methods**:
  - Constructors (parameterized and default).
  - `setCustomerData()`: Collects and sets customer and account data.
  - `performTransactions()`: Allows performing deposits and withdrawals.
  - `displayCustomerDetails()`: Displays customer's details and account information.

## Usage Instructions

1. **Compile the Program**:
   To compile the C++ code, use the following command:
   ```bash
   g++ -o banking_system banking_system.cpp
2. **Run the Program: Execute the compiled program**:
./banking_system
Interact with the System: Follow the on-screen prompts to:
3. **Interact with the System: Follow the on-screen prompts to**:
Create new customer profiles.
Perform deposits and withdrawals.
View customer details and transaction history.
**Example**
Create a Customer:

Enter customer details (name, ID, contact information).
Enter account details (number, initial balance, type).
Record an initial deposit.
Perform Transactions:

Choose to deposit or withdraw funds.
View updated balance and transaction history.
View Customer Details:

Display customer information and transaction history.
## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

For any questions or feedback, please reach out to hussiene188@gmail.com
