#include "Shop.h"
#include <iostream>
#include <iomanip>

void Shop::add()
{
	if (indActiveUser != -1)
	{
		productManager.add();
	}
	else {
		std::cout << "No user logged in.\n";
	}
}

void Shop::addToCart()
{
	if (indActiveUser != -1)
	{
		std::cout << "Enter number of product from list to add in cart: ";
		int pos;
		std::cin >> pos;
		if (pos >= 0 && pos < productManager.getNumProducts()) {
			Product* productToAdd = productManager.getProduct(pos)->clone();
			userManager.addToCart(indActiveUser, productToAdd);
		}
		else {
			std::cout << "Wrong number." << std::endl;
		}
	}
	else {
		std::cout << "No user logged in.\n";
	}
}

void Shop::change()
{
	if (indActiveUser != -1)
	{
		productManager.change();
	}
	else {
		std::cout << "No user logged in.\n";
	}
}

void Shop::remove()
{
	if (indActiveUser != -1)
	{
		productManager.remove();
	}
	else {
		std::cout << "No user logged in.\n";
	}
}

void Shop::removeFromCart()
{
	if (indActiveUser != -1)
	{
		userManager.removeFromCart(indActiveUser);
	}
	else {
		std::cout << "No user logged in.\n";
	}
}

void Shop::print() const
{
	productManager.print();
}

void Shop::printCart() const
{
	if (indActiveUser != -1)
	{
		userManager.printCart(indActiveUser);
	}
	else {
		std::cout << "No user logged in.\n";
	}
}

int Shop::login() {
	indActiveUser = userManager.login();
	return indActiveUser;
}

int Shop::registerUser() {
	indActiveUser = userManager.registerUser();
	return indActiveUser;
}

void Shop::changePassword() {
	userManager.changePassword(indActiveUser);
}