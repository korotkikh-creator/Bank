#include "Account.hpp"
#include "AccountList.hpp"
#include "Bank.hpp"
#include "Repository.hpp"

#include "googletest/googletest/include/gtest/gtest.h"



/**
 * функция создания аккаунта
 * @param bank
 */
void createAccount(Bank &bank) {
    std::string number;
    
    
    do {
        std::cout << "Enter your phone number: ";
        std::cin >> number;
        if (bank.searchByNumber(number) != nullptr)
            throw UserExistsException("The user with this number already exists");
        if (number.size() != 11)
            std::cout << "The phone number must contain exactly 11 characters" << std::endl;
    } while (number.size() != 11);

    std::cout << "Please enter your last name: ";
    std::string surname;
    std::cin >> surname;

    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;

    std::cout << "Enter middle name: ";
    std::string middleName;
    std::cin >> middleName;

    std::cout << "Enter a balance: ";
    double balance;
    std::cin >> balance;
    
    bank.addAccount(Account(number, surname, name, middleName, balance));
}

GTEST_API_ int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Russian");

    testing::InitGoogleTest(&argc, argv);
    int r = RUN_ALL_TESTS();

    std::cout << "Do you want to upload a file or work with a new bank?" << std::endl;
    std::cout << "Select the answer option you need by entering a number:\n1) Load bank from file\n2) Create a new bank"
         << std::endl;
    int n;
    
    std::cin >> n;
    Bank bank;
    std::string filename;
    
    if (n == 1) {
        
        
        while (true) {
            
            
            try {
                
                std::cout << "Enter the name of the file from which you want to load the bank" << std::endl;
                std::cin >> filename;
                
                bank = Repository(filename).getBank();
                break;
            }
            catch (FileNotFoundException e) {
                
                
                
                std::cout << e.getMessage() << std::endl;
            }
        }
    } else if (n == 2) {
        
        
        
        bank = Bank();
        std::cout << "How many accounts do you want to add?" << std::endl;
        int count;
        std::cin >> count;
        
        
        
        for (int i = 0; i < count;) {
            std::cout << "Create an account number " << (i + 1) << std::endl;
            try {
                
                createAccount(bank);
                i++;
            }
            catch (UserExistsException u) {
                std::cout << u.getMessage() << std::endl;
            }
            std::cout << "\n";
        }
    } else {
        std::cout << "Number entered incorrectly, please try again";
        return 1;
    }

    
    
    while (true) {
        std::cout << "Select the operation you need from the list: " << std::endl;
        std::cout << "1) Creating and adding a new account" << std::endl;
        std::cout << "2) One-bank transfer" << std::endl;
        std::cout << "3) Removing an account from the bank" << std::endl;
        std::cout << "4) Saving a bank to another file" << std::endl;
        std::cout << "5) Updating the bank in the source file" << std::endl;
        std::cout << "6) Display the bank (list of accounts) on the screen" << std::endl;
        std::cout << "7) Remove bank from source file" << std::endl;
        std::cout << "8) Log out" << std::endl;
        int m;
        std::cin >> m;
        
        switch (m) {
            case 1:
                try {
                    createAccount(bank);
                }
                catch (UserExistsException u) {
                    std::cout << u.getMessage() << std::endl;
                }
                break;
            case 2: {
                
                std::cout << "Enter the phone number of the account from which the transfer is made: ";
                std::string senderNumber;
                std::cin >> senderNumber;

                std::cout << "Enter the phone number of the account to which the amount will be transferred: ";
                std::string receiveNumber;
                std::cin >> receiveNumber;

                std::cout << "Enter the amount you want to transfer: ";
                double sum;
                std::cin >> sum;

                
                
                try {
                    bank.transaction(senderNumber, receiveNumber, sum);
                }
                catch (UserNotFoundException us) {
                    std::cout << us.getMessage() << std::endl;
                }
                catch (SumIsBiggerThanBalance s) {
                    std::cout << s.getMessage() << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "Enter the phone number of the account you want to delete: ";
                std::string delNumber;
                std::cin >> delNumber;
                
                Account *delAcc = bank.searchByNumber(delNumber);
                
                if (delAcc == nullptr) {
                    std::cout << "Account is not found!" << std::endl;
                } else
                    
                    bank.deleteAccount(*delAcc);
                break;
            }
            case 4: {
                std::cout << "Enter the name of the file you want to save the bank to: ";
                
                std::string newFilename;
                std::cin >> newFilename;
                Repository repSave(bank);
                try {
                    
                    repSave.Save(newFilename);
                }
                catch (FileErrorException f) {
                    std::cout << f.getMessage() << std::endl;
                }
                break;
            }
            case 5: {
                
                
                if (filename == "")
                    std::cout << "Firstly, save the bank to a file!" << std::endl;
                else {
                    
                    
                    Repository repUpdate(bank);
                    try {
                        repUpdate.Update(filename);
                    } catch (FileErrorException f) {
                        std::cout << f.getMessage() << std::endl;
                    }
                }
                break;
            }
            case 6:
                
                
                std::cout << "Bank: " << std::endl;
                std::cout << bank << std::endl;
                break;
            case 7: {
                
                
                if (filename == "")
                    std::cout << "Unable to delete a bank because there is no place to delete it from!" << std::endl;
                else {
                    
                    
                    
                    
                    
                    Repository repDelete(bank);
                    try {
                        repDelete.Delete(filename);
                    } catch (FileErrorException f) {
                        std::cout << f.getMessage() << std::endl;
                    }
                }
                break;
            }
            case 8:
                
                
                return 0;
            default:
                
                std::cout << "Operation number entered incorrectly, please, try again" << std::endl;
                break;
        }
    }
    return 0;
