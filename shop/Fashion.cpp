#include "Fashion.h"
#include <iostream>
#include <cstring>

Fashion::Fashion(product type) : Product(type) { }

std::istream& Fashion::input(std::istream& in)
{
	Product::input(in);

	std::cout << "Enter size:";
	in >> size;

	return in;
}

std::ostream& Fashion::print(std::ostream& out) const
{
	out << type
		<< "\n\tName: " << name
		<< "\n\tDescription: " << description
		<< "\n\tBrand: " << brand
		<< "\n\tSize: " << size
		<< "\n\tPrice: " << price
		<< "\n\tIn stock: " << inStock << std::endl;

	return out;
}
