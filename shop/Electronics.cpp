#include "Electronics.h"
#include <iostream>
#include <cstring>

Electronics::Electronics(product type) : Product(type), displaySize(0)
{
	model = new char[1];
	model[0] = '\0';
	colour = new char[1];
	colour[0] = '\0';
}

Electronics::Electronics(const Electronics& rhs) : Product(rhs), displaySize(rhs.displaySize)
{
	int len = strlen(rhs.model);
	model = new char[len + 1];
	for (int i = 0; i <= len; i++)
	{
		model[i] = rhs.model[i];
	}

	len = strlen(rhs.colour);
	colour = new char[len + 1];
	for (int i = 0; i <= len; i++)
	{
		colour[i] = rhs.colour[i];
	}
}

Electronics& Electronics::operator=(const Electronics& rhs)
{
	if (this != &rhs)
	{
		Product::operator=(rhs);
		delete[] model;
		delete[] colour;

		displaySize = rhs.displaySize;

		int len = strlen(rhs.model);
		model = new char[len + 1];
		for (int i = 0; i <= len; i++)
		{
			model[i] = rhs.model[i];
		}

		len = strlen(rhs.colour);
		colour = new char[len + 1];
		for (int i = 0; i <= len; i++)
		{
			colour[i] = rhs.colour[i];
		}
	}
	return *this;
}

std::istream& Electronics::input(std::istream& in)
{
	Product::input(in);

	const int MAX_SIZE = 300; // Default maximum size of dynamic array

	delete[] model;
	delete[] colour;

	model = new char[MAX_SIZE];
	colour = new char[MAX_SIZE];

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

Electronics::~Electronics()
{
	delete[] model;
	delete[] colour;
}
