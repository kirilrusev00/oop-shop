#include "User.h"
#include <iostream>
#include <cstring>

const int MAX_SIZE = 50;

User::User()
{
	username = new char[1];
	username[0] = '\0';
	password = new char[1];
	password[0] = '\0';
	cart = Cart();
	bankAccount = BankAccount();
}

User::User(const User& rhs) : bankAccount(rhs.bankAccount)
{
	int size = strlen(rhs.username);
	username = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		username[i] = rhs.username[i];
	}

	size = strlen(rhs.password);
	password = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		password[i] = rhs.password[i];
	}

	cart = rhs.cart;
}

User& User::operator=(const User& rhs)
{
	if (this != &rhs)
	{
		delete[] username;
		delete[] password;

		int size = strlen(rhs.username);
		username = new char[size + 1];
		for (int i = 0; i <= size; i++)
		{
			username[i] = rhs.username[i];
		}

		size = strlen(rhs.password);
		password = new char[size + 1];
		for (int i = 0; i <= size; i++)
		{
			password[i] = rhs.password[i];
		}

		cart = rhs.cart;
		bankAccount = rhs.bankAccount;
	}
	return *this;
}

void User::setPassword() {
	char* oldPass = new char[MAX_SIZE];
	
	std::cout << "Enter old password: ";
	std::cin >> oldPass;

	if (strcmp(oldPass, password) == 0) {
		char* newPass = new char[MAX_SIZE];
		
		std::cout << "Enter new password: ";
		std::cin >> newPass;
		
		setPassword(newPass);
		std::cout << "Password changed successfully!\n";

		delete[] newPass;
	}
	else {
		std::cout << "Password does not match!\n";
	}

	delete[] oldPass;
}

void User::setPassword(const char* newPassword) {
	if (newPassword != nullptr) {
		delete[] password;

		int size = strlen(newPassword);
		password = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			password[i] = newPassword[i];
		}
	}
}

void User::addToCart(Product* productToAdd) {
	cart.add(productToAdd);
}

void User::removeFromCart() {
	std::cout << "Enter number of product in cart to remove from cart: ";
	int pos;
	std::cin >> pos;
	cart.remove(pos);
}

void User::printCart() const {
	cart.print();
}

std::istream& operator>>(std::istream& in, User& user) {
	return user.input(in);
}

std::istream& User::input(std::istream& in)
{
	delete[] username;
	delete[] password;

	username = new char[MAX_SIZE];
	password = new char[MAX_SIZE];
	std::cout << "Enter username:";
	in >> username;
	std::cout << "Enter password:";
	in >> password;
	std::cout << "Enter bank account:" << std::endl;
	in >> bankAccount;

	return in;
}

User::~User()
{
	delete[] username;
	delete[] password;
}
