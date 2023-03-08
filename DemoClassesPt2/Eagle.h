#pragma once
#include "Animal.h"
class Eagle :
    virtual public Animal
{
public:
    Eagle();
    Eagle(int a_nLegs);
    void Move(void);
};

