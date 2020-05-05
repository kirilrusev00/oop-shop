#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

class Product
{
public:
	enum product {
		laptop,
		phone,
		shirt,
		sneakers,
		tshirt,
		another
	};

	Product(product type = another);
	Product(const Product&);
	Product& operator=(const Product&);

	virtual Product* clone() const = 0;

	const int getInStock() const { return inStock; }

	~Product();

	friend std::istream& operator>>(std::istream&, Product&);
	friend std::ostream& operator<<(std::ostream&, const Product&);

protected:
	product type;
	char* name;
	char* description;
	char* brand;
	double price;
	int inStock;

	virtual std::istream& input(std::istream&);
	virtual std::ostream& print(std::ostream&) const = 0;
};

std::ostream& operator<<(std::ostream&, const Product::product&);

#endif
