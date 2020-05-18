#ifndef CART_H
#define CART_H
#include "Product.h"
#include <vector>

class Cart{
private:
	std::vector<Product*> products;

public:
	Cart() { };

	void add(Product*);
	void remove(const int& pos);
	void print() const;
};

#endif
