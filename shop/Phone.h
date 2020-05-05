#ifndef PHONE_H
#define PHONE_H
#include "Electronics.h"

class Phone : public Electronics
{
public:
	Phone();

	virtual Product* clone() const override { return new Phone(*this); }
};

#endif
