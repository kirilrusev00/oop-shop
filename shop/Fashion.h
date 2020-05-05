#ifndef FASHION_H
#define FASHION_H
#include "Product.h"

class Fashion : public Product
{
private:
	char* size;

	std::istream& input(std::istream&);
	std::ostream& print(std::ostream&) const;
	
protected:
	Fashion(product type = another);
	Fashion(const Fashion&);
	Fashion& operator=(const Fashion&);

public:
	virtual Product* clone() const = 0;

	~Fashion();
};

#endif