#include "Test.hpp"
#include "googletest/googletest/include/gtest/gtest.h"


TEST(test2, c2) {
    Account acc1("0", "Ivanov", "Ivan", "Ivanovich", 200.01);
    Account acc2("1", "Sidorov", "Petr", "Petrovich", 30.59);
    acc1.transaction(acc2, 30.00);
    EXPECT_EQ(170.01, acc1.getBalance());
    EXPECT_EQ(60.59, acc2.getBalance());
}

TEST(test3, c3) {
    Account acc1("0", "Ivanov", "Ivan", "Ivanovich", 200.01);
    Account acc2("1", "Sidorov", "Petr", "Petrovich", 30.59);
    ASSERT_THROW(acc1.transaction(acc2, 250.00), SumIsBiggerThanBalance);
}

TEST(test4, c4) {
    Account acc1("0", "Ivanov", "Ivan", "Ivanovich", 200.01);
    AccountList accLst;
    accLst.addUser(acc1);
    EXPECT_EQ(acc1, accLst[0]);
}

TEST(test5, c5) {
    Account acc1("0", "Ivanov", "Ivan", "Ivanovich", 200.01);
    AccountList accLst;
    accLst.addUser(acc1);
    ASSERT_THROW(accLst.addUser(acc1), UserExistsException);
}

TEST(test6, c6) {
    Account acc1("0", "Ivanov", "Ivan", "Ivanovich", 200.01);
    AccountList accLst;
    accLst.addUser(acc1);
    Account *findAcc = accLst.searchByNumber("0");
    EXPECT_EQ(*findAcc, acc1);
}

TEST(test7, c7) {
    Account acc1("0", "Ivanov", "Ivan", "Ivanovich", 200.01);
    Bank bank(0);
    bank.addAccount(acc1);
    bank.deleteAccount(acc1);
    EXPECT_EQ(true, !bank.existsAccount(acc1));
}

TEST(test8, c8) {
    Repository rep("Bank.csv");
    Bank bank(0);
    EXPECT_EQ(bank, rep.getBank());
}

TEST(test9, c9) {
    Account acc1("0", "Ivanov", "Ivan", "Ivanovich", 200.01);
    Account acc2("1", "Sidorov", "Petr", "Petrovich", 30.59);

    AccountList accLst2;
    accLst2.addUser(acc1);
    accLst2.addUser(acc2);
    Account indexAcc1 = accLst2[0];
    EXPECT_EQ(indexAcc1, acc1);
}

TEST(test10, c10) {
    Bank bank1(1);
    bank1.addAccount(Account("0", "Ivanov", "Ivan", "Ivanovich", 200.01));
    bank1.addAccount(Account("1", "Sidorov", "Petr", "Petrovich", 30.59));
    Repository rep1(bank1);
    Bank getBank = rep1.getBank();
    EXPECT_EQ(getBank.getCode(), bank1.getCode());
}

TEST(test11, c11) {
    Account acc1("0", "Ivanov", "Ivan", "Ivanovich", 200.01);
    AccountList accLst;
    accLst.addUser(acc1);
    Account *findAcc = accLst.searchByNumber("1");
    EXPECT_EQ(findAcc, nullptr);
}

TEST(test12, c12) {
    Bank bank(0);
    Account acc1("0", "Ivanov", "Ivan", "Ivanovich", 200.01);
    bank.addAccount(acc1);
    bank.deleteAccount(acc1);
    ASSERT_THROW(bank.deleteAccount(acc1), EmptyListException);
}

TEST(test13, c13) {
    ASSERT_THROW(Repository rep("bank3.csv"), FileNotFoundException);
}

TEST(test14, c14) {
    Repository rep("bank2.csv");
    rep.Delete("");
    Bank bank(0);
    EXPECT_EQ(rep.getBank(), bank);
}

TEST(test15, c15) {
    Account acc1("0", "Ivanov", "Ivan", "Ivanovich", 200.01);
    Account acc2("1", "Sidorov", "Petr", "Petrovich", 30.59);

    AccountList accLst2;
    accLst2.addUser(acc1);
    accLst2.addUser(acc2);
    ASSERT_THROW(Account indexAcc1 = accLst2[3], IndexOfRangeException);
}