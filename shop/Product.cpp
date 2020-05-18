#include "Product.h"
#include <iostream>

Product::Product(Product::product _type) :price(0), inStock(0)
{
	type = _type;
}

std::istream& Product::input(std::istream& in) {
	std::cout << "Enter name:";
	in >> name;
	std::cout << "Enter description:";
	in >> description;
	std::cout << "Enter brand:";
	in >> brand;
	std::cout << "Enter price:";
	in >> price;
	std::cout << "Enter how much in stock:";
	in >> inStock;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Product::product& type)
{
	if (type == Product::laptop)
	{
		out << "laptop";
	}
	else if (type == Product::phone)
	{
		out << "phone";
	}
	else if (type == Product::shirt)
	{
		out << "shirt";
	}
	else if (type == Product::sneakers)
	{
		out << "sneakers";
	}
	else if (type == Product::tshirt)
	{
		out << "tshirt";
	}
	else if (type == Product::another)
	{
		out << "another";
	}
	return out;
}

std::istream& operator>>(std::istream& in, Product& product)
{
	return product.input(in);
}

std::ostream& operator<<(std::ostream& out, const Product& product)
{
	return product.print(out);
}