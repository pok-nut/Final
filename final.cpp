#include "bank.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int main() {
	//3 types of accounts: savings, checking, and credit;

	int dollars;
	int cents;
	int accType;
	int counter = 0;
	size_t i;
	size_t j;
	int input = 0;

	bool available = false;
	bool found = false;

	BankAcc currAcc;
	vector<BankAcc> userAcc;



	do {
		cout << "1: Display all" << endl;
		cout << "2: Display account" << endl;
		cout << "3: Open new account" << endl;
		cout << "4: Deposit" << endl;
		cout << "5: Withdraw" << endl;
		cout << "6: quit" << endl;

		cin >> input;
		switch (input) {
		case 1:
			if (userAcc.size() == 0) {
				cout << "No accounts" << endl;
			}
			for (i = 0; i < userAcc.size(); ++i) {
				currAcc = userAcc.at(i);
			
					if (currAcc.GetType() == 1) {
						cout << "Checking: ";
					}
					else if (currAcc.GetType() == 2) {
						cout << "Saving: ";
					}
					else if (currAcc.GetType() == 3) {
						cout << "Credit: ";
					}



				if (currAcc.GetCents() < 10) {
					cout << "$" << currAcc.GetDollars() << ".0" << currAcc.GetCents() << endl;
				}
				else {
					cout << "$" << currAcc.GetDollars() << "." << currAcc.GetCents() << endl;
				}


			}
			break;
		case 2:
			if (userAcc.size() == 0) {
				cout << "No accounts" << endl;
				break;
			}
			cout << "Which account did you want to access?" << endl;
			cout << "Checking (1), Saving (2), Credit (3)" << endl;

			do {
				found = false;
				cin >> accType;
				while (accType < 1 || accType > 3) {
					cout << "Invalid choice. Please try again" << endl;
					cin >> accType;
				}

			
				for (i = 0; i < userAcc.size(); ++i) {
					currAcc = userAcc.at(i);

					if (currAcc.GetType() == accType) {
						found = true;
						break;
					}
				}

				if (!found) {
					cout << "The account doesn't exist. Please select an existing account" << endl;

				}
				else {
					switch (accType) {
					case 1:
						cout << "Checking: ";
						break;
					case 2:
						cout << "Saving: ";
						break;
					case 3:
						cout << "Credit: ";
						break;
					}

					if (currAcc.GetCents() < 10) {
						cout << "$" << currAcc.GetDollars() << ".0" << currAcc.GetCents() << endl;
					}
					else {
						cout << "$" << currAcc.GetDollars() << "." << currAcc.GetCents() << endl;
					}
				}
			} while (!found);
			break;
		case 3:
			if (userAcc.size() == 3) {
				cout << "You have opened every possible account." << endl;
				break;
			}

			available = false;
			cout << "What kind of account would you like to open?" << endl;
			cout << "You can only open one of each." << endl;
			cout << "Enter the number. Checking (1), Saving (2), Credit (3)." << endl;

			while (!available) {
				cin >> accType;
				while (accType < 1 || accType > 3) {
					cout << "Invalid choice. Please try again" << endl;
					cin >> accType;
				}
				available = true;
				for (i = 0; i < userAcc.size(); ++i) {
					currAcc = userAcc.at(i);
					if (currAcc.GetType() == accType) {
						available = false;
						cout << "Account has already been opened. Please select a new account." << endl;
						break;
					}
					
				}
				
			}

			cout << "How much money did you want to deposit?" << endl;
			cout << "Dollars: ";
			cin >> dollars;
			cout << "Cents: ";
			cin >> cents;

			currAcc.SetInfo(dollars, cents, accType);
			userAcc.push_back(currAcc);

			

			break;

		case 4:
			found = false;
			if (userAcc.size() == 0) {
				cout << "You haven't opened any accounts" << endl;
				break;
			}

			cout << "Which account did you want to access?" << endl;
			cout << "Checking (1), Saving (2), Credit (3)" << endl;

			do {
				cin >> accType;
				while (accType < 1 || accType > 3) {
					cout << "Invalid choice. Please try again" << endl;
					cin >> accType;
				}

				for (i = 0; i < userAcc.size(); ++i) {
					currAcc = userAcc.at(i);

					if (currAcc.GetType() == accType) {
						found = true;
						break;
					}
				}

				if (!found) {
					cout << "The account doesn't exist. Please select an existing account" << endl;
				}
				else {
					cout << "How much money did you want to deposit?" << endl;
					cout << "Dollars: ";
					cin >> dollars;
					cout << "Cents: ";
					cin >> cents;

					for (i = 0; i < userAcc.size(); ++i) {
						currAcc = userAcc.at(i);

						if (currAcc.GetType() == accType) {
							currAcc.Deposit(dollars, cents);
							userAcc.at(i) = currAcc;
						}
					}

				}
			} while (!found);
			break;
		case 5:
			found = false;
			if (userAcc.size() == 0) {
				cout << "You haven't opened any accounts" << endl;
				break;
			}

			cout << "Which account did you want to access?" << endl;
			cout << "Checking (1), Saving (2), Credit (3)" << endl;

			do {
				cin >> accType;
				while (accType < 1 || accType > 3) {
					cout << "Invalid choice. Please try again" << endl;
					cin >> accType;
				}

				for (i = 0; i < userAcc.size(); ++i) {
					currAcc = userAcc.at(i);

					if (currAcc.GetType() == accType) {
						found = true;
						break;
					}
				}

				if (!found) {
					cout << "The account doesn't exist. Please select an existing account" << endl;
				}
				else {
					cout << "How much money did you want to withdraw?" << endl;
					cout << "Dollars: ";
					cin >> dollars;
					cout << "Cents: ";
					cin >> cents;

					for (i = 0; i < userAcc.size(); ++i) {
						currAcc = userAcc.at(i);

						if (currAcc.GetType() == accType) {
							if ((currAcc.GetCents() < cents) && (currAcc.GetDollars() <= dollars)) {
								cout << "You don't have that much money in the account." << endl;
							}
							else {
								currAcc.Withdraw(dollars, cents);
								userAcc.at(i) = currAcc;
							}

						}
					}

				}
			} while (!found);
			break;
		case 6:
			cout << "Thank you. Please come again!" << endl;
			break;
		default:
			cout << "Invalid choice. Please try again" << endl;
			break;

		}
	} while (input != 6);








}

