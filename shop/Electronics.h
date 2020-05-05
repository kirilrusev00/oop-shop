#ifndef ELECTRONICS_H
#define ELECTRONICS_H
#include "Product.h"

class Electronics : public Product
{
private:
	char* model;
	char* colour;
	double displaySize;

	std::istream& input(std::istream&);
	std::ostream& print(std::ostream&) const;

protected:
	Electronics(product type = another);
	Electronics(const Electronics&);
	Electronics& operator=(const Electronics&);

public:
	virtual Product* clone() const = 0;

	~Electronics();
};

#endif
