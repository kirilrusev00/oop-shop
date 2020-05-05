#include "CommandExecutor.h"

void CommandExecutor::printMenuLogin() {
	std::cout << std::endl;
	std::cout << "1\t" << "Login" << std::endl;
	std::cout << "2\t" << "Register" << std::endl;
	std::cout << "3\t" << "Continue without logging in" << std::endl;
	std::cout << std::endl;
}

void CommandExecutor::printMenuShopForLoggedUsers() {
	std::cout << std::endl;
	std::cout << "1\t" << "Add new product to shop" << std::endl;
	std::cout << "2\t" << "Add new product to cart" << std::endl;
	std::cout << "3\t" << "Change product in shop" << std::endl;
	std::cout << "4\t" << "Delete product from shop" << std::endl;
	std::cout << "5\t" << "Remove product from cart" << std::endl;
	std::cout << "6\t" << "Print products in shop" << std::endl;
	std::cout << "7\t" << "Print products in cart" << std::endl;
	std::cout << "8\t" << "Change password" << std::endl;
	std::cout << "9\t" << "Quit" << std::endl;
	std::cout << std::endl;
}

void CommandExecutor::printMenuShopForNotLoggedUsers() {
	std::cout << std::endl;
	std::cout << "1\t" << "Print products in shop" << std::endl;
	std::cout << "2\t" << "Quit" << std::endl;
	std::cout << std::endl;
}

void CommandExecutor::executeCommandsForLogin() {
	std::cout << "Welcome to the shop" << std::endl;
	int option;
	do {
		printMenuLogin();
		std::cout << "Choose an option:";
		std::cin >> option;
		switch (option)
		{
		case 1:
			shop.setActiveUser(shop.login());
			break;
		case 2:
			shop.setActiveUser(shop.registerUser());
			break;
		case 3:
			break;
		default:
			std::cout << "Wrong option!\n";
		}
	} while (option < 1 && option > 3);
}

void CommandExecutor::executeCommandsInShop() {
	if (shop.getActiveUser() == -1) {
		executeCommandsInShopForNotLoggedUsers();
	}
	else {
		executeCommandsInShopForLoggedUsers();
	}
}

void CommandExecutor::executeCommandsInShopForLoggedUsers() {
	int option;
	do
	{
		printMenuShopForLoggedUsers();
		std::cout << "Choose an option:";
		std::cin >> option;
		switch (option)
		{
		case 1:
			shop.add();
			break;
		case 2:
			shop.addToCart();
			break;
		case 3:
			shop.change();
			break;
		case 4:
			shop.remove();
			break;
		case 5:
			shop.removeFromCart();
			break;
		case 6:
			shop.print();
			break;
		case 7:
			shop.printCart();
			break;
		case 8:
			shop.changePassword();
			break;
		case 9:
			std::cout << "Quitting shop" << std::endl;
			break;
		default:
			std::cout << "Wrong option!\n";
		}
	} while (option != 9);
}

void CommandExecutor::executeCommandsInShopForNotLoggedUsers() {
	int option;
	do
	{
		printMenuShopForNotLoggedUsers();
		std::cout << "Choose an option:";
		std::cin >> option;
		switch (option)
		{
		case 1:
			shop.print();
			break;
		case 2:
			std::cout << "Quitting shop" << std::endl;
			break;
		default:
			std::cout << "Wrong option!\n";
		}
	} while (option != 2);
}