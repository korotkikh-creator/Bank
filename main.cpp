#include "Account.h"
#include "AccountList.h"

int main() {
    Account acc1("1", "Ivanov", "Ivan", "Ivanovich", 200.01);
    Account acc2("2", "Sidorov", "Petr", "Petrovich", 30.59);
    Account acc3("3", "Petrov", "Vladimir", "Romanovich", 150.97);
    acc1.increaseBalance(10.09);
    cout << acc1 << endl;
    //acc1.decreaseBalance(10.09);
    //cout << acc1 << endl;
    acc1.transaction(acc2, 20.56);
    //cout << acc1 << endl;
    //cout << acc2 << endl;
    //cout << acc1;

    /*Account acc2;
    cin >> acc2;
    cout << acc2 << endl;*/

    try {
        AccountList accLst;
        accLst.addUser(acc1);
        accLst.addUser(acc2);
        //accLst.addUser(acc3);
        cout << accLst << endl;

        //accLst.deleteUser(acc1);
        //cout << accLst << endl;

        //accLst.addUser(acc2);
        //cout << accLst << endl;

        //accLst.deleteUser(acc3);
        //cout << accLst << endl;

        //cout << accLst.getLastAccount() << endl;
        //cout << accLst.getFirstAccount() << endl;

        //cout << accLst[1] << endl;
        //cout << accLst[0] << endl;
        //cout << accLst[3] << endl;

    }
    catch (UserExistsException u) {
        cout << u.getMessage();
    }
    catch (EmptyListException e) {
        cout << e.getMessage();
    }
    catch (IndexOfRangeException i) {
        cout << i.getMessage();
    }

    return 0;
}