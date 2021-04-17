#include "Repository.h"
#include "Exceptions.h"
#include <fstream>

Repository::Repository(const string& filename) {
	ifstream ifs(filename);
	if (!ifs)
		throw FileNotFoundException("The file wasn't found");
	this->filename = filename;
	ifs >> this->bank;
	ifs.close();
}

Repository::Repository(const Bank& bank) {
	this->bank = bank;
}

Bank& Repository::getBank() {
	return this->bank;
}

void Repository::Save(string filename = "") {
	if (filename == "")
		filename = this->filename;
	this->filename = filename;
	ofstream of(this->filename);
	if (!of)
		throw FileErrorException("File error");
	of << this->bank << endl;
	of.close();
}

void Repository::Delete(string filename = "") {
	if (filename == "")
		filename = this->filename;
	this->filename = filename;
	ofstream of(this->filename);
	if (!of)
		throw FileErrorException("File error");
	of.close();
}

void Repository::Update(string filename = "") {
	Save(filename);
}