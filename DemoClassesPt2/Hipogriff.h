#pragma once
#include "Eagle.h"
#include "Lion.h"

class Hipogriff : public Eagle, public Lion
{
public:
	Hipogriff();
	Hipogriff(int a_nLegs);
	void Move(void);
};

