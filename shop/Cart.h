#ifndef CART_H
#define CART_H
#include "Product.h"
#include "Vector.hpp"

class Cart{
private:
	Vector<Product*> products;

public:
	Cart() { };

	void add(Product*);
	void remove(const int& pos);
	void print() const;
};

#endif
