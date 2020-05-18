#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>

class BankAccount {
private:
	std::string bankName;
	std::string iban;

	std::istream& input(std::istream&);

public:
	BankAccount();

	friend std::istream& operator>>(std::istream&, BankAccount&);
};


#endif