#include "User.h"
#include <iostream>
#include <cstring>

User::User()
{
	cart = Cart();
	bankAccount = BankAccount();
}

void User::setPassword() {
	std::string oldPass;
	
	std::cout << "Enter old password: ";
	std::cin >> oldPass;

	if (oldPass.compare(password) == 0) {
		std::string newPass;
		
		std::cout << "Enter new password: ";
		std::cin >> newPass;
		
		setPassword(newPass);
		std::cout << "Password changed successfully!\n";
	}
	else {
		std::cout << "Password does not match!\n";
	}
}

void User::setPassword(const std::string& newPassword) {
	password = newPassword;
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
	std::cout << "Enter username:";
	in >> username;
	std::cout << "Enter password:";
	in >> password;
	std::cout << "Enter bank account:" << std::endl;
	in >> bankAccount;

	return in;
}
