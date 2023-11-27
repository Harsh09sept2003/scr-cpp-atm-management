#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Bank {
private:
    string name;
    long long accnumber;
    string password; // Added password field
    char type[10];
    long long amount = 0;
    long long tot = 0;

    // Transaction history
    vector<string> transactions;

public:
    // Function to set the person's data along with a password
    void setvalue() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Account number: ";
        cin >> accnumber;

        cout << "Enter password: ";
        cin >> password;

        cout << "Enter Account type: ";
        cin >> type;

        cout << "Enter Balance: ";
        cin >> tot;
    }

    // Function to display the required data
    void showdata() {
        cout << "Name: " << name << endl;
        cout << "Account No: " << accnumber << endl;
        cout << "Account type: " << type << endl;
        cout << "Balance: " << tot << endl;
    }

    // Function to authenticate the user with a password
    bool authenticate() {
        string enteredPassword;
        cout << "Enter password: ";
        cin >> enteredPassword;
        return enteredPassword == password;
    }

    // Function to deposit the amount in ATM
    void deposit() {
        cout << "\nEnter amount to be Deposited: ";
        cin >> amount;
        tot += amount;

        // Add transaction to history
        transactions.push_back("Deposit: " + to_string(amount));
    }

    // Function to show the balance amount
    void showbal() {
        cout << "\nTotal balance is: " << tot << endl;
    }

    // Function to withdraw the amount in ATM
    void withdrawl() {
        int withdrawalAmount;
        cout << "Enter amount to withdraw: ";
        cin >> withdrawalAmount;

        if (withdrawalAmount > tot) {
            cout << "Insufficient funds!" << endl;
        } else {
            tot -= withdrawalAmount;

            // Add transaction to history
            transactions.push_back("Withdrawal: " + to_string(withdrawalAmount));

            cout << "Withdrawal successful. Available Balance is " << tot << endl;
        }
    }

    // Function to display transaction history
    void showTransactionHistory() {
        cout << "\nTransaction History:\n";
        for (const auto& transaction : transactions) {
            cout << "- " << transaction << endl;
        }
    }
};

int main() {
    Bank b;

    int choice;

    while (1) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~WELCOME~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~\n\n";
        cout << "Enter Your Choice\n";
        cout << "\t1. Enter name, Account number, Account type, and Password\n";
        cout << "\t2. Balance Enquiry\n";
        cout << "\t3. Deposit Money\n";
        cout << "\t4. Show Total balance\n";
        cout << "\t5. Withdraw Money\n";
        cout << "\t6. Show Transaction History\n";
        cout << "\t7. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                b.setvalue();
                break;
            case 2:
                if (b.authenticate()) {
                    b.showdata();
                } else {
                    cout << "Authentication failed. Please try again.\n";
                }
                break;
            case 3:
                if (b.authenticate()) {
                    b.deposit();
                } else {
                    cout << "Authentication failed. Please try again.\n";
                }
                break;
            case 4:
                if (b.authenticate()) {
                    b.showbal();
                } else {
                    cout << "Authentication failed. Please try again.\n";
                }
                break;
            case 5:
                if (b.authenticate()) {
                    b.withdrawl();
                } else {
                    cout << "Authentication failed. Please try again.\n";
                }
                break;
            case 6:
                if (b.authenticate()) {
                    b.showTransactionHistory();
                } else {
                    cout << "Authentication failed. Please try again.\n";
                }
                break;
            case 7:
                exit(0);
                break;
            default:
                cout << "\nInvalid choice\n";
        }
    }
}
