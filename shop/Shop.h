#ifndef SHOP_H
#define SHOP_H
#include "UserManager.h"
#include "ProductManager.h"

class Shop
{
private:
	UserManager userManager = UserManager::getInstance();
	ProductManager productManager = ProductManager::getInstance();
	int indActiveUser;

	Shop() : indActiveUser(-1) {}
public:
	static Shop& getInstance() {
		static Shop instance;
		return instance;
	}

	const int getActiveUser() const { return indActiveUser; }
	void setActiveUser(const int& newIndActiveUser) { indActiveUser = newIndActiveUser; }

	void add();
	void addToCart();
	void change();
	void remove();
	void removeFromCart();
	void print() const;
	void printCart() const;

	int login();
	int registerUser();
	void changePassword();
};


#endif
