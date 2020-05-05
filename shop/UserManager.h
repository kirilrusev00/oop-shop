#ifndef USERMANAGER_H
#define USERMANAGER_H
#include "User.h"
#include "Product.h"
#include "Vector.hpp"

class UserManager {
private:
	Vector<User> users;

	UserManager() { }

public:
	static UserManager& getInstance() {
		static UserManager instance;
		return instance;
	}

	int login();
	int registerUser();
	void changePassword(const int&);

	void addToCart(const int&, Product*);
	void removeFromCart(const int&);
	void printCart(const int&) const;
};

#endif
