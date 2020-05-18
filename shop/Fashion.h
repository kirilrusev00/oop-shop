#ifndef FASHION_H
#define FASHION_H
#include "Product.h"
#include <string>

class Fashion : public Product
{
private:
	std::string size;

	std::istream& input(std::istream&);
	std::ostream& print(std::ostream&) const;
	
protected:
	Fashion(product type = another);

public:
	virtual Product* clone() const = 0;

};

#endif