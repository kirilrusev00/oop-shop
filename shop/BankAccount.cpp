#include "BankAccount.h"
#include <iostream>
#include <cstring>

BankAccount::BankAccount() { }

std::istream& BankAccount::input(std::istream& in)
{
	std::cout << "Enter bank name:";
	in >> bankName;
	
	std::cout << "Enter IBAN:";
	in >> iban;
	
	return in;
}

std::istream& operator>>(std::istream& in, BankAccount& bankAccount) {
	return bankAccount.input(in);
}

