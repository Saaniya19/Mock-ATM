#include <iostream>
#include <string>

using namespace std;

class atm {
private:
    long int accountNum;
    string name;
    int PIN;
    double balance;
    string mobileNum;

public:
    void setData(long int accountIn, string nameIn, int pinIn, double balanceIn, string mobileIn) {
        accountNum = accountIn; name = nameIn; PIN = pinIn; balance = balanceIn; mobileNum = mobileIn;
    }
    long int getAccountNum() {
        return accountNum;
    }
    string getName() {
        return name;
    }
    int getPIN() {
        return PIN;
    }
    double getBalance() {
        return balance;
    }
    string getMobile() {
        return mobileNum;
    }
    void makeAccount() {
        cout << "Your account number is 12345678" << endl;
        accountNum = 12345678;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your mobile number: ";
        cin >> mobileNum;
        cout << "Enter a 4 digit PIN: ";
        cin >> PIN;
        cout << "Enter the amount of money you would like to store in your account: ";
        cin >> balance;
        cout << "Your accunt has been successfully created." << endl << endl;
    }
    void showDetails() {
        cout << "Your account number is " << accountNum << "." << endl;
        cout << "The name registered to this account is " << name << "." << endl;
        cout << "Your PIN number is " << PIN << "." << endl;
        cout << "Your current balance is " << balance << "." << endl;
        cout << "The mobile number registered to this account is " << mobileNum << endl;
    }
    void setMobile(string mobileOld, string mobileNew) {
        if (mobileOld.compare(mobileNum) == 0) {
            mobileNum = mobileNew;
            cout << "Your mobile number has been updated successfully." << endl;
            //_getch();   //will hold the screen until the user presses any screen --> doesn't work on macs anymore
        }
    }
    int verify() {
        long int accountIn;
        int pinIn;
        cout << "Enter your account number: ";
        cin >> accountIn;
        cout << "Enter your PIN number: ";
        cin >> pinIn;
        cout << accountNum << ", " << PIN << endl;
        if ((accountIn == accountNum) && (pinIn = PIN)) return 1;
        else return 0;
    }
    void cashWithdrawl (int amount) {
        if (amount > 0 && amount < balance) {
            balance -= amount;
            cout << "You now have $" << balance << " in your bank account." << endl;
            //_getch();
        } else {
            cout << "You can not withdraw this amount from your account." << endl;
        }
    }

};

int main() {
    int choice = 0, enterPIN = 0;
    long int enterAccountNum;

    //this is used to clear the screen when a key is pressed by user
    //system("cls");

    atm user1;
    int signIn;
    cout << endl;
    cout << "Please select from the following options: " << endl;
    cout << "1. Make a new account" << endl;
    cout << "2. Log into an existing account" << endl;
    cin >> signIn;
    if (signIn == 1) {
        user1.makeAccount();
    }
    
    //user1.setData(12345678, "Saaniya", 1111, 9200.91, "5195742063");
    
    do {
        //system("cls");
        cout << "Welcome to our ATM! Please log in below." << endl;
        if (user1.verify() == 1) {
            do {
                int amount = 0, choice;
                string oldMobile, newMobile;
                //system("cls");

                cout << "Please select from the following options." << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Cash Withdraw" << endl;
                cout << "3. Show User Details" << endl;
                cout << "4. Update Mobile Number" << endl;
                cout << "5. Exit" << endl;
                cin >> choice;

                if (choice == 1) {
                    cout << "Your current balance is " << user1.getBalance() << endl << endl; 
                    //_getch();
                } else if (choice == 2) {
                    cout << "Enter the amount you woukld like to withdraw: ";
                    cin >> amount;
                    user1.cashWithdrawl(amount);
                    cout << endl;
                    //_getch();
                } else if (choice == 3) {
                    user1.showDetails();
                    cout << endl;
                    //_getch();
                } else if (choice == 4) {
                    cout << "Enter your current mobile number: ";
                    getline(cin, oldMobile);
                    cout << "Enter your new mobile number: ";
                    getline(cin, newMobile);
                    user1.setMobile(oldMobile, newMobile);
                    cout << endl;
                    //_getch();
                } else {
                    exit(0);
                }
            } while (1);
        } else cout << "The credentials you entered are incorrect." << endl;
    } while (1);

    return 0;
}