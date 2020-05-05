#include "Fashion.h"
#include <iostream>
#include <cstring>

Fashion::Fashion(product type) : Product(type)
{
	size = new char[1];
	size[0] = '\0';
}

Fashion::Fashion(const Fashion& rhs) : Product(rhs)
{
	int len = strlen(rhs.size);
	size = new char[len + 1];
	for (int i = 0; i <= len; i++)
	{
		size[i] = rhs.size[i];
	}
}

Fashion& Fashion::operator=(const Fashion& rhs)
{
	if (this != &rhs)
	{
		Product::operator=(rhs);
		delete[] size;

		int len = strlen(rhs.size);
		size = new char[len + 1];
		for (int i = 0; i <= len; i++)
		{
			size[i] = rhs.size[i];
		}
	}
	return *this;
}

std::istream& Fashion::input(std::istream& in)
{
	Product::input(in);

	const int MAX_SIZE = 300; // Default maximum size of dynamic array

	delete[] size;
	size = new char[MAX_SIZE];

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

Fashion::~Fashion()
{
	delete[] size;
}
