#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>

class BankAccount {
private:
	char* bankName;
	char* iban;

	std::istream& input(std::istream&);

public:
	BankAccount();
	BankAccount(const BankAccount&);
	BankAccount& operator=(const BankAccount&);

	friend std::istream& operator>>(std::istream&, BankAccount&);

	~BankAccount();
};


#endif