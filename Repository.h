#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Bank.h"

using namespace std;

class Repository {
	Bank bank;
	string filename;

public:
	Repository(const string& filename);
	Repository(const Bank& bank);
	Bank& getBank();
	void Save(string filename);
	void Delete(string filename);
	void Update(string filename);
};

#endif
