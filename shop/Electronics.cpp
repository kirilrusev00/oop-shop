#include "Electronics.h"
#include <iostream>
#include <cstring>

Electronics::Electronics(product type) : Product(type), displaySize(0) { }

std::istream& Electronics::input(std::istream& in)
{
	Product::input(in);

	std::cout << "Enter model:";
	in >> model;
	std::cout << "Enter colour:";
	in >> colour;
	std::cout << "Enter display size:";
	in >> displaySize;

	return in;
}

std::ostream& Electronics::print(std::ostream& out) const
{
	out << type
		<< "\n\tName: " << name
		<< "\n\tDescription: " << description
		<< "\n\tBrand: " << brand
		<< "\n\tModel: " << model
		<< "\n\tColour: " << colour
		<< "\n\tPrice: " << price
		<< "\n\tDisplay size: " << displaySize
		<< "\n\tIn stock: " << inStock << std::endl;

	return out;
}
