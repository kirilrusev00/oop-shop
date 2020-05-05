#include "BankAccount.h"
#include <iostream>
#include <cstring>

BankAccount::BankAccount()
{
	bankName = new char[1];
	bankName[0] = '\0';
	iban = new char[1];
	iban[0] = '\0';
}

BankAccount::BankAccount(const BankAccount& rhs)
{
	int size = strlen(rhs.bankName);
	bankName = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		bankName[i] = rhs.bankName[i];
	}

	size = strlen(rhs.iban);
	iban = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		iban[i] = rhs.iban[i];
	}
}

BankAccount& BankAccount::operator=(const BankAccount& rhs)
{
	if (this != &rhs)
	{
		delete[] bankName;
		delete[] iban;

		int size = strlen(rhs.bankName);
		bankName = new char[size + 1];
		for (int i = 0; i <= size; i++)
		{
			bankName[i] = rhs.bankName[i];
		}

		size = strlen(rhs.iban);
		iban = new char[size + 1];
		for (int i = 0; i <= size; i++)
		{
			iban[i] = rhs.iban[i];
		}
	}
	return *this;
}

std::istream& BankAccount::input(std::istream& in)
{
	const int MAX_SIZE = 300; // Default maximum size of dynamic array
	
	delete[] bankName;
	delete[] iban;
	
	bankName = new char[MAX_SIZE];
	iban = new char[MAX_SIZE];
	
	std::cout << "Enter bank name:";
	in >> bankName;
	
	std::cout << "Enter IBAN:";
	in >> iban;
	
	return in;
}

std::istream& operator>>(std::istream& in, BankAccount& bankAccount) {
	return bankAccount.input(in);
}

BankAccount::~BankAccount()
{
	delete[] bankName;
	delete[] iban;
}
