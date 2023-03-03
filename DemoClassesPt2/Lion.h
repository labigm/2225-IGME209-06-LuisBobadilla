#pragma once
#include "Animal.h"
class Lion :
    public Animal
{
public:
    Lion();
    Lion(int a_nLegs);
    void Move(void);
};

