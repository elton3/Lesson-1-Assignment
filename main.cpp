#include <iostream>
#include <string>
using namespace std;

class bankAccount {
private:
    string accountHolderName;
    double accountNumber = 0;
    double balance = 0;

public:
    bankAccount(string name, double accountNum, double firstDep ) {
        accountHolderName = name;
        accountNumber = accountNum;
        balance = firstDep;

    }
    void deposit(double dep) {

        balance = balance + dep;
        cout << "Deposit was successful! Current Balance: $" << balance << endl;

    }
    void withdraw(double with) {

        if (with > balance) {
            cout << "Insufficint funds!" << endl;
        }
        balance = balance - with;
        cout << "New Balance: $" << balance;

    }

    void getBalance() {
        cout << "Current Balence: $" << balance << endl;
    }
};

int main() {
    bankAccount *account  = nullptr;
    int choice =0;

    do {

            cout << "\nWelcome to Simple Bank System\n" << endl;
            cout << "1. Create Account" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Check Balance" << endl;
            cout << "5. Exit" << endl << endl;
            cout << "\nEnter your choice: " <<endl;
            cin >> choice;
            cin.ignore();

        switch (choice) {
            case 1: {
                string name;
                int accNum;
                double firstdep;

                cout << "Enter your account name: " << endl;
                cin >> name;
                accNum = 0;
                cout << "Enter your initial deposit: ";
                cin >> firstdep;

                account = new bankAccount(name,accNum,firstdep);
            }
                break;
            case 2: {
                int dep;
                cout << "Enter amount to Deposit: ";
                cin >> dep;
                account->deposit(dep);
            }
                break;
            case 3: {
                int with;
                cout << "Enter ammount to withdrawl: ";
                cin >> with;
                account->withdraw(with);
            }
                break;
            case 4: {
                account->getBalance();
            }
                break;
            case 5: {
                delete account;
                return 0;
            }
                break;

        }

    } while (choice != 5);

}