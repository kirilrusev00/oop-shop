#ifndef USER_H
#define USER_H
#include "BankAccount.h"
#include "Cart.h"

class User {
private:
	char* username;
	char* password;
	BankAccount bankAccount;
	Cart cart;

	void setPassword(const char*);

	std::istream& input(std::istream&);

public:
	User();
	User(const User&);
	User& operator=(const User&);
	
	char* getUsername() const { return username; }
	char* getPassword() const { return password; }
	void setPassword();

	void addToCart(Product*);
	void removeFromCart();
	void printCart() const;

	friend std::istream& operator>>(std::istream&, User&);

	~User();
};


#endif