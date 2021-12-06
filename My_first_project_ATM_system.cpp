#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

/*Features it contain------
 *Check Balance
 *Cash Withdrawl
 *User Details
 *Update Mob.No
 */

class atm
{

private: // private member variable
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;

public: // public member functions
    // setData function is setting the data into the private member variables
    void setData(long int youraccount_No, string yourname, int yourPIN, double yourbalance, string yourmobile_No)
    {
        account_No = youraccount_No; // assigning the formal arguments to the private member variables
        name = yourname;
        PIN = yourPIN;
        balance = yourbalance;
        mobile_No = yourmobile_No;
    }

    // getAccount function is returning the user's account no.
    long int getAccount_No()
    {
        return account_No;
    }

    // getName function is returning the user's name
    string getName()
    {
        return name;
    }

    // getPIN function is returning the user's PIN
    int getPIN()
    {
        return PIN;
    }

    // getBalance function is returning the user's Bank Balance
    double getBalance()
    {
        return balance;
    }

    // getMobile_No function is returning the user mobile no
    string getMobile_No()
    {
        return mobile_No;
    }

    // setMobile function is Updating the user's mobile no.
    void setMobile(string mob_prev, string mob_new)
    {
        if (mob_prev == mobile_No) // it will check old mobile no
        {
            mobile_No = mob_new; // update with new one if old matches
            cout << "Mobile No. successfully updated";
            _getch(); // getch is used to hold the screen until the user press any key
        }
        else
        {
            cout << "Incorrect Old Mobile No.";
            _getch();
        }
    }

    // cashWithdraw function is used to withdraw the money from ATM
    void cashWithdraw(int amount)
    {
        if (amount > 0 && amount <= balance) // check entered amount validity
        {
            balance -= amount; // balance = balance-amount
            cout << "Please Collect Your Cash" << endl;
            cout << "Available Balance is " << balance;
            _getch(); // getch is used to hold the screen until the user press any key
        }
        else
        {

            cout << endl
                 << "Invalid Input or Insufficient Balance";
            _getch();
        }
    }
};

int main()
{
    int choice = 0, enterPIN; // for user authentication
    long int enterAccountNo;

    system("cls");

    // creating object using class
    atm user1;
    // Set user details (into object)
    user1.setData(12345678, "Skp", 1111, 45000.00, "7544050639");

    do
    {
        system("cls");

        cout << "........WelCome to ATM........." << endl;
        cout << "Enter your Account No :"; // asking user to enter account no.
        cin >> enterAccountNo;

        cout << "Enter PIN :"; // asking user to enter PIN
        cin >> enterPIN;

        // check whether enter values matches with user details
        if ((enterAccountNo == user1.getAccount_No()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system("cls");

                cout << "Welcome to the ATM\n\n";
                cout << "Select Option\n----------------\n";
                cout << "1.Check Balance\n";
                cout << "2.Cash Withdrawl\n";
                cout << "3.Show user Details\n";
                cout << "4.Update mobile no.\n";
                cout << "5.Exit\n\n";
                cin >> choice; // taking user choice

                switch (choice) // switch condition
                {
                case 1: // if user press 1
                    cout << "Your Bank balance is :" << user1.getBalance();
                    // getBalance is.....printing the users bank balance
                    _getch();
                    break;

                case 2: // if user press 2
                    cout << "Enter the amount :";
                    cin >> amount;
                    user1.cashWithdraw(amount); // calling withdraw function by passing the withdraw amount

                    break;

                case 3: // if user press 3
                    cout << endl
                         << "User Details are :-";
                    cout << endl
                         << "Account no :-" << user1.getAccount_No();
                    cout << endl
                         << "Name :-" << user1.getName();
                    cout << endl
                         << "Balance :-" << user1.getBalance();
                    cout << endl
                         << "Mobile No. :-" << user1.getMobile_No();
                    // getting and printing user details
                    _getch();
                    break;

                case 4: // if user press 4
                    cout << endl
                         << "Enter Old Mobile No. "; // taking old mobile no
                    cin >> oldMobileNo;
                    cout << "Enter New Mobile No. "; // taking new mobile no
                    cin >> newMobileNo;

                    user1.setMobile(oldMobileNo, newMobileNo); // set new mobile no by calling setMobile function
                    break;

                case 5:      // if user press 5
                    exit(0); // exit application

                default:
                    cout << endl
                         << "Enter Valid Data";
                }

            } while (1);
        }
        else
        {
            cout << "Invalid Account No. or Password";
            _getch();
        }

    } while (1);

    return 0;
}