#ifndef SHIRT_H
#define SHIRT_H
#include "Fashion.h"

class Shirt : public Fashion
{
public:
	Shirt();

	virtual Product* clone() const override { return new Shirt(*this); }
};

#endif
