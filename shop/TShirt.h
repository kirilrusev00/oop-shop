#ifndef TSHIRT_H
#define TSHIRT_H
#include "Fashion.h"

class TShirt : public Fashion
{
public:
	TShirt();

	virtual Product* clone() const override { return new TShirt(*this); }
};

#endif
