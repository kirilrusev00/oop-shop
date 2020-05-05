#ifndef SNEAKERS_H
#define SNEAKERS_H
#include "Fashion.h"

class Sneakers : public Fashion
{
public:
	Sneakers();

	virtual Product* clone() const override { return new Sneakers(*this); }
};

#endif
