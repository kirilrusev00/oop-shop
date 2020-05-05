#include "UserManager.h"
#include <iostream>

int UserManager::login() {
	const int MAX_SIZE = 300; // Default maximum size of dynamic array
	char* username = new char[MAX_SIZE];
	char* password = new char[MAX_SIZE];
	std::cout << "Enter username:";
	std::cin >> username;
	std::cout << "Enter password:";
	std::cin >> password;
	for (int i = 0; i < users.getSize(); i++) {
		if (strcmp(username, users[i].getUsername()) == 0 && strcmp(password, users[i].getPassword()) == 0) {
			std::cout << "Login successful." << std::endl;

			delete[] username;
			delete[] password;

			return i;
		}
	}
	std::cout << "User with this username does not exist." << std::endl;

	delete[] username;
	delete[] password;
	return -1;
}

int UserManager::registerUser() {
	User newUser;
	std::cin >> newUser;
	for (int i = 0; i < users.getSize(); i++) {
		if (strcmp(newUser.getUsername(), users[i].getUsername()) == 0) {
			std::cout << "User with this username exists." << std::endl;
			return -1;
		}
	}
	users.push_back(newUser);
	std::cout << "Successful registration." << std::endl;
	return users.getSize() - 1;
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