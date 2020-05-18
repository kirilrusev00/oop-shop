#ifndef USER_H
#define USER_H
#include "BankAccount.h"
#include "Cart.h"
#include <string>

class User {
private:
	std::string username;
	std::string password;
	BankAccount bankAccount;
	Cart cart;

	void setPassword(const std::string&);

	std::istream& input(std::istream&);

public:
	User();
	
	const std::string& getUsername() const { return username; }
	const std::string& getPassword() const { return password; }
	void setPassword();

	void addToCart(Product*);
	void removeFromCart();
	void printCart() const;

	friend std::istream& operator>>(std::istream&, User&);
};


#endif