#pragma once
#include "Coffee.h"
#include "IngredientsDecorator.h"
class CoffeeFactory
{
public:
	CoffeeFactory(void);
	~CoffeeFactory(void);

	Coffee* makeCoffee(int coffeeID);
};

