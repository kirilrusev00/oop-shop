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
	if (pos >= 0 && pos < products.size())
	{
		products.erase(products.begin() + pos);
	}
	else {
		std::cout << "Wrong position \n";
	}
}

void Cart::print() const
{
	if (products.size() > 0) {
		for (auto& i : products) {
			std::cout << *i << " ";
		}
		std::cout << "\n";
	}
	else {
		std::cout << "Cart is empty" << "\n";
	}
}