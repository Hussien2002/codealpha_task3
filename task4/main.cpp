#include <iostream>
#include <vector>
using namespace std;
class transaction{
private:
     string trnsactionid;
    string type;
    string date;
    double amount;
public:
    //parameter cons.
    transaction(const string& t,const string &TYPE,const string &DATE,const double &Amount )
    {
        trnsactionid=t;
        type=TYPE;
        date=DATE;
        amount=Amount;
    }
    //empty cons.
    transaction()
    :trnsactionid(" "),type(" "),date(" "),amount(0){}
    ;
    void settransationid(const string &t)
    {
        trnsactionid=t;
    }
    void settransationtype(const string &T)
    {
        type=T;
    }
    void settransactiondate(const string &D)
    {
        date=D;
    }
    void settransactionamount(const double A)
    {
        amount=A;
    }
    string gettransationid() {return trnsactionid;}
    string gettransationtype(){return type;}
    string gettransactiondate(){return date;}
    double gettransactionamount(){return amount;}
    void transdisplay() const
    {
        cout<<"Transaction Id : "<< trnsactionid ;
        cout<<" ,Type of transaction :"<<type;
        cout<<" ,Date :"<<date;
        cout<<" ,Amount of transaction :"<<amount<<"\n";
    }



};
class account {
private:
     string account_number;
    double balance;
    string account_type;
    vector<transaction> TRANSACTION;
public:
   //parameter cons.
    account( string t, double Balace, string accounttype,vector<transaction> y )
    {
        account_number=t;
        balance=Balace;
        account_type=accounttype;
        TRANSACTION=y;
    }
    //empty cons.
    account()
    :account_number(" "),balance(0),account_type(" "),TRANSACTION(){}
    ;
     void setaccountnumber(const string& n)
    {
        account_number=n;
    }

void deposit(double amount)
{
    if(amount>0)
    {
        balance +=amount;
         transaction depositTransaction("T001", "Deposit", "2024-08-25", amount);
            TRANSACTION.push_back(depositTransaction);  // Add to transaction history
        cout<<"The New balance is :"<<balance<<"\n";
    }
    else
    {
        cout<<"Invalid \n";
    }
}
void withdraw(double amount)
{
    if(amount>0&&amount<=balance)
    {
        balance -=amount;
         transaction withdrawTransaction("T002", "Withdraw", "2024-08-25", amount);
            TRANSACTION.push_back(withdrawTransaction);  // Add to transaction history
        cout<<"The New balance is :"<<balance<<"\n";
    }
    else if (amount>balance)
    {
        cout << "Insufficient funds \n";
    }
    else
    {
        cout<<"Invalid \n";

}
}
string getaccountnumber()
    {
        return account_number;
    }
    double getbalance()
    {
        return balance;
    }
    string getaccounttype()
    {

        return account_type;
    }
        const vector<transaction> &getTransactions() const {
        return TRANSACTION;
    }
   void displayTransactions()   {
        cout << "Transaction History:\n";
        for (const auto& t : TRANSACTION) {
            t.transdisplay();
        }
    }

};
class customer{
private :
    string name ;
    string id;
    string contact_info;
    account Account;//create OBJECT FROM account class to composition with customer
    transaction TRAN;//create object from transaction class to composition with customer by account (via relation)
public:
    //parameter cons.
    customer( string n, string ID, string CONTACT,account A,transaction T )
    {
        name=n;
        id=ID;
        contact_info=CONTACT;
        Account=A;
        TRAN=T;
    }
    //initial cons.
    customer()
    :name(" "),id(" "),contact_info(" "),Account(),TRAN(){}
    ;
    void setname(const string& n)
    {
        name=n;
    }
    void setid(const string& i)
    {
        id=i;
    }
    void setcontact_info(const string& c)
    {
        contact_info=c;
    }
    void setaccountdata() {
    string accountNumber;
    double balance;
    string accountType;
    string transactionID, transactionType, date;
    cout<<"Please Enter Customer Name : " ;
    cin>>name;
     cout<<"Please Enter Customer ID : ";
     cin>>id;
     cout<<"Please Enter contact information of customer :";
     cin>>contact_info;
    cout << "Please Enter Account Number: ";
    cin >> accountNumber;

    cout << "Please Enter Initial Balance: ";
    cin >> balance;

    cout << "Please Enter Account Type (e.g., Checking or Savings): ";
    cin >> accountType;

    // Gathering transaction details
    cout << "Please Enter Transaction ID: ";
    cin >> transactionID;

    cout << "Enter the transaction type (deposit/withdrawal): ";
    cin >> transactionType;

    cout << "Please Enter Transaction Date: ";
    cin >> date;
    transaction initial(transactionID, transactionType,date,balance);//initial object to store data in transaction
    vector<transaction> trans;
    trans.push_back(initial);//add stored data to the vector
     Account = account(accountNumber, balance, accountType, trans);
    }
    void performTransactions() {
        int choice;
        double amount;
        cout << "\n--- Transaction Menu ---\n";
        cout << "1. Deposit\n2. Withdraw\n3. Exit\n";
        do {
            cout << "Choose a transaction: ";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter deposit amount: ";
                cin >> amount;
                Account.deposit(amount);
            } else if (choice == 2) {
                cout << "Enter withdraw amount: ";
                cin >> amount;
                Account.withdraw(amount);
            } else if (choice == 3) {
                cout << "Exiting transaction menu.\n";
            } else {
                cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 3);
    }
    string getname()const
    {
        return name;
    }
    string getid() const
    {
        return id;
    }
    string getcontact()const
    {
        return contact_info;
    }

    void displayCustomerDetails()  {
        cout << "Customer Name: " << getname() << "\n";
        cout << "Customer ID: " << getid() << "\n";
        cout << "Contact Information: " << getcontact() << "\n";
        cout << "Account Number: " << Account.getaccountnumber() << "\n";
        cout << "Account Balance: " << Account.getbalance() << "\n";
        cout << "Account Type: " << Account.getaccounttype() << "\n";
        Account.displayTransactions();//to display history of transaction

    }
};
int main()
{
   vector<customer> customers;
    int choice;
    do {
        cout << "\n--- Banking System Menu ---\n";
        cout << "1. Create Customer\n2. Perform Transactions\n3. View Customer Details\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            customer newCustomer;
            newCustomer.setaccountdata();
            customers.push_back(newCustomer);
        } else if (choice == 2) {
            if (customers.empty()) {
                cout << "No customers available. Please create a customer first.\n";
            } else {
                int customerIndex;
                cout << "Select Customer (0 to " << customers.size() - 1 << "): ";
                cin >> customerIndex;
                if (customerIndex >= 0 && customerIndex < customers.size()) {
                    customers[customerIndex].performTransactions();
                } else {
                    cout << "Invalid customer selection.\n";
                }
            }
        } else if (choice == 3) {
            if (customers.empty()) {
                cout << "No customers available. Please create a customer first.\n";
            } else {
                int customerIndex;
                cout << "Select Customer (0 to " << customers.size() - 1 << "): ";
                cin >> customerIndex;
                if (customerIndex >= 0 && customerIndex < customers.size()) {
                    customers[customerIndex].displayCustomerDetails();
                } else {
                    cout << "Invalid customer selection.\n";
                }
            }
        } else if (choice != 4) {
            cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 4);

    cout << "Exiting the Banking System. Goodbye!\n";

    return 0;


}
