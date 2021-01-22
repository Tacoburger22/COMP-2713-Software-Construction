//Isaac Weiss icw0001
//Project1.cpp
//TO COMPILE: 
//"g++ -std=c++11 Project1.cpp -o Project1", then "./Project1"
//
//I used Codecademy to learn the basics of C++.
//I used StackOverflow for miscellaneous help.
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    double loan, interestRate, monthly, totalInterest;
    double monthlyInterest, principal;
    int months = 0;
    string loanString;

    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "\nLoan Amount: ";
    cin >> loan;
    loanString = to_string(loan);
    loanString.erase(remove(loanString.begin(), loanString.end(), ','), loanString.end());
    loan = stoi(loanString);
    if (loan < 50) {
        cin.clear();
        cin.ignore(1000,'\n');
        loan *= 1000;
    }
    while (cin.fail() || loan <= 0) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Loan Amount (please insert a positive loan amount): ";
        cin >> loan;
    }
    cout << "Interest Rate (% per year): ";
    cin >> interestRate;
    while (cin.fail() || interestRate <= 0) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Interest Rate (% per year) (please insert a positive interest rate): ";
        cin >> interestRate;
    }
    interestRate /= 1200;
    cout << "Monthly Payments: ";
    //cout << "\nLoan: " << loan << "\nInterest Rate: " << interestRate;
    cin >> monthly;
    while (cin.fail() || monthly <= 0 || monthly > loan || monthly < (loan*.01)) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Monthly Payments (please insert a positive monthly payment that is at least 1% of the loan): ";
        cin >> monthly;
    }
    cout << endl;
    cout << "*************************************************************************\n"
 << "\t\t\tAmortization Table\n"
 << "*************************************************************************\n"
 << "Month\tBalance\t\tPayment\t\tRate\tInterest\tPrincipal\n";
    while (loan > 0) {
        if (months == 0) {
            cout << months++ << "\t$" << loan; 
            if (loan < 1000) cout << " ";
            cout << "\tN/A\t\tN/A\tN/A\t\tN/A\n";
        } else {
            cout << months++ << "\t";
            //if (months >= 10) cout << " ";
            monthlyInterest = loan * interestRate;
            if (loan < monthly) {
                monthly = loan + monthlyInterest;
            }
            totalInterest += monthlyInterest;
            principal = monthly - monthlyInterest;
            loan -= principal;
            cout << "$" << loan << "\t";
            if (loan < 1000) cout << "\t";
            //if (loan < 1000 && loan > 99) cout << " ";
            //if (loan < 100 && loan > 9) cout << " ";
            //if (loan < 10) cout << " ";
            cout << monthly << "\t\t";
            if (monthly < 10) cout << " ";
            cout << (interestRate*100) << "\t$" << monthlyInterest;
            //if (monthlyInterest < 10) cout << " ";
            cout << "\t\t$" << principal << "\n";
        }
        
    }
    cout << "*************************************************************************\n\n";
    cout << "It takes " << --months << " months to pay off the loan.\n";
    cout << "Total interest paid is: " << totalInterest;

}
