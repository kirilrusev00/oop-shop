#include "UserManager.h"
#include <iostream>
#include <string>

int UserManager::login() {
	std::string username;
	std::string password;
	std::cout << "Enter username:";
	std::cin >> username;
	std::cout << "Enter password:";
	std::cin >> password;
	for (int i = 0; i < users.size(); i++) {
		if (username.compare(users[i].getUsername()) == 0 && password.compare(users[i].getPassword()) == 0) {
			std::cout << "Login successful." << std::endl;

			return i;
		}
	}
	std::cout << "User with this username does not exist." << std::endl;

	return -1;
}

int UserManager::registerUser() {
	User newUser;
	std::cin >> newUser;
	for (int i = 0; i < users.size(); i++) {
		if (newUser.getUsername().compare(users[i].getUsername()) == 0) {
			std::cout << "User with this username exists." << std::endl;
			return -1;
		}
	}
	users.push_back(newUser);
	std::cout << "Successful registration." << std::endl;
	return users.size() - 1;
}

void UserManager::changePassword(const int& indUser) {
	users[indUser].setPassword();
}

void UserManager::addToCart(const int& indUser, Product* productToAdd) {
	users[indUser].addToCart(productToAdd);
}

void UserManager::removeFromCart(const int& indUser) {
	users[indUser].removeFromCart();
}

void UserManager::printCart(const int& indUser) const {
	users[indUser].printCart();
}