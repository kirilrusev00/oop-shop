#include "Cart.h"
#include <iostream>

void Cart::add(Product* product)
{
	if (product->getInStock() > 0) {
		products.push_back(product);
	}
	else {
		std::cout << "Product not in stock." << std::endl;
	}
}

void Cart::remove(const int& pos)
{
	if (pos >= 0 && pos < products.getSize())
	{
		products.remove(pos);
	}
	else {
		std::cout << "Wrong position \n";
	}
}

void Cart::print() const
{
	if (products.getSize() > 0) {
		std::cout << products << "\n";
	}
	else {
		std::cout << "Cart is empty" << "\n";
	}
}