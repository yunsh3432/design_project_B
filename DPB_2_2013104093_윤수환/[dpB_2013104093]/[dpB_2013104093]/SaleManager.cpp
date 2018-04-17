#include "SaleManager.h"


SaleManager::SaleManager(void)
{
	price = 10000;
}


SaleManager::~SaleManager(void)
{
}

void SaleManager::changrprice(int _price)
{
	price = _price;
}

int SaleManager::getprice()
{
	return price;
}

bool SaleManager::reduceMoney(int money)
{
	if (price - money < 0)
		return false;
	price -= money;
	return true;
}