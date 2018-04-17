#include "Coffee.h"


Coffee::Coffee(void)
{
}


Coffee::~Coffee(void)
{
}

BaseCoffee::BaseCoffee(void)
{
}


BaseCoffee::~BaseCoffee(void)
{
}

int BaseCoffee::getCost()
{
	return 2000;
}

vector<int> BaseCoffee::GetIngredientsID()
{
	vector<int> ids;
	ids.push_back(1);
	return ids;
}