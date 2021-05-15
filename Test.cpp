#include "Test.h"

void TestAll() {
	Account acc1("0", "Ivanov", "Ivan", "Ivanovich", 200.01);
	Account acc2("1", "Sidorov", "Petr", "Petrovich", 30.59);

	acc1.transaction(acc2, 30.00); // no error
	if (acc1.getBalance() == 170.01)
		cout << "Test passed" << endl;
	else
		cerr << "Test failed" << endl;

	if (acc2.getBalance() == 60.59)
		cout << "Test passed" << endl;
	else
		cerr << "Test failed" << endl;

	try {
		acc1.transaction(acc2, 250.00); // error
		cerr << "Test failed" << endl;
	}
	catch (SumIsBiggerThanBalance s) {
		cout << "Test passed" << endl;
	}


	AccountList accLst;
	accLst.addUser(acc1); //no error
	if (accLst[0] == acc1)
		cout << "Test passed" << endl;
	else
		cerr << "Test failed" << endl;

	try {
		accLst.addUser(acc1); //error
		cerr << "Test failed" << endl;
	}
	catch (UserExistsException u) {
		cout << "Test passed" << endl;
	}


	Account* findAcc = accLst.searchByNumber("0"); //no error
	if (findAcc != nullptr && *findAcc == acc1)
		cout << "Test passed" << endl;
	else
		cerr << "Test failed" << endl;

	Account* findAcc1 = accLst.searchByNumber("1"); //error
	if (findAcc1 == nullptr)
		cout << "Test passed" << endl;
	else
		cerr << "Test failed" << endl;


	Bank bank(0);
	bank.addAccount(acc1);
	bank.deleteAccount(acc1); //no error
	if (!bank.existsAccount(acc1))
		cout << "Test passed" << endl;
	else
		cerr << "Test failed" << endl;

	try {
		bank.deleteAccount(acc2); //error
		cerr << "Test failed" << endl;
	}
	catch (EmptyListException e) {
		cout << "Test passed" << endl;
	}

	try {
		Repository rep("bank3.csv"); //error
		cerr << "Test failed" << endl;
	}
	catch (FileNotFoundException f) {
		cout << "Test passed" << endl;
	}

	try {
		Repository rep("Bank.csv"); //no error
		cout << "Test passed" << endl;
	}
	catch (FileNotFoundException f) {
		cerr << "Test failed" << endl;
	}

	Repository rep("bank2.csv");
	try {
		rep.Delete(""); //no error
		cout << "Test passed" << endl;
	}
	catch (FileErrorException f) {
		cerr << "Test failed" << endl;
	}


	AccountList accLst2;
	accLst2.addUser(acc1);
	accLst2.addUser(acc2);

	Account indexAcc1 = accLst2[0]; //no error
	if (indexAcc1 == acc1)
		cout << "Test passed" << endl;
	else
		cerr << "Test failed" << endl;

	try {
		Account indexAcc2 = accLst2[3]; //error
		cerr << "Test failed" << endl;
	}
	catch (IndexOfRangeException i) {
		cout << "Test passed" << endl;
	}

	Bank bank1(1);
	bank1.addAccount(acc1);
	bank1.addAccount(acc2);
	Repository rep1(bank1);
	Bank getBank = rep1.getBank();
	if (getBank.getCode() == bank1.getCode())
		cout << "Test passed" << endl;
	else
		cerr << "Test failed" << endl;
}