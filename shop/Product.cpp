#include "Product.h"
#include <iostream>

Product::Product(Product::product _type) :price(0), inStock(0)
{
	type = _type;
	name = new char[1];
	name[0] = '\0';
	description = new char[1];
	description[0] = '\0';
	brand = new char[1];
	brand[0] = '\0';
}

Product::Product(const Product& rhs) :type(rhs.type), price(rhs.price), inStock(rhs.inStock)
{
	int len = strlen(rhs.name);
	name = new char[len + 1];
	for (int i = 0; i <= len; i++)
	{
		name[i] = rhs.name[i];
	}

	len = strlen(rhs.description);
	description = new char[len + 1];
	for (int i = 0; i <= len; i++)
	{
		description[i] = rhs.description[i];
	}

	len = strlen(rhs.brand);
	brand = new char[len + 1];
	for (int i = 0; i <= len; i++)
	{
		brand[i] = rhs.brand[i];
	}
}

Product& Product::operator=(const Product& rhs)
{
	if (this != &rhs)
	{
		delete[] name;
		delete[] description;
		delete[] brand;

		type = rhs.type;
		price = rhs.price;
		inStock = rhs.inStock;

		int len = strlen(rhs.name);
		name = new char[len + 1];
		for (int i = 0; i <= len; i++)
		{
			name[i] = rhs.name[i];
		}

		len = strlen(rhs.description);
		description = new char[len + 1];
		for (int i = 0; i <= len; i++)
		{
			description[i] = rhs.description[i];
		}

		len = strlen(rhs.brand);
		brand = new char[len + 1];
		for (int i = 0; i <= len; i++)
		{
			brand[i] = rhs.brand[i];
		}
	}
	return *this;
}

std::istream& Product::input(std::istream& in) {
	const int MAX_SIZE = 300; // Default maximum size of dynamic array

	delete[] name;
	delete[] description;
	delete[] brand;

	name = new char[MAX_SIZE];
	description = new char[MAX_SIZE];
	brand = new char[MAX_SIZE];

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

Product::~Product()
{
	delete[] name;
	delete[] description;
	delete[] brand;
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