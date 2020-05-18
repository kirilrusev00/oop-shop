#ifndef ELECTRONICS_H
#define ELECTRONICS_H
#include "Product.h"
#include <string>

class Electronics : public Product
{
private:
	std::string model;
	std::string colour;
	double displaySize;

	std::istream& input(std::istream&);
	std::ostream& print(std::ostream&) const;

protected:
	Electronics(product type = another);

public:
	virtual Product* clone() const = 0;

};

#endif
