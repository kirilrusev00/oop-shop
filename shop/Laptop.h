#ifndef LAPTOP_H
#define LAPTOP_H
#include "Electronics.h"

class Laptop : public Electronics
{
public:
	Laptop();

	virtual Product* clone() const override { return new Laptop(*this); }
};

#endif
