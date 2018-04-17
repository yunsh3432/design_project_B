#include "StockManager.h"
#include<iostream>

using namespace std;

StockManager::StockManager(void)
{
	coffeeStock = 3;
	milkStock = 3;
	mochaStock = 3;
	shotStock = 3;
	whipStock = 3;
}


StockManager::~StockManager(void)
{
}

bool StockManager::addStockByIngredientsID(vector<int> ingredientsID)
{
	for (int i = 0; i < ingredientsID.size(); i++)
	{
		switch (ingredientsID[i])
		{
		case 1: 
			coffeeStock++;
			break;
		case 2:
			milkStock++;
			break;
		case 3:
			mochaStock++;
			break;
		case 4:
			shotStock++;
			break;
		case 5:
			whipStock++;
			break;
		default:
			return false;
		}
	}
	return true;
}

bool StockManager::reduceStockByIngredientsID(vector<int> ingeredientsID)
{
	bool flag = false;
	for (int i = 0; i < ingeredientsID.size(); i++)
	{
		switch (ingeredientsID[i])
		{
		case 1:
			coffeeStock--;
			if (coffeeStock < 0)
				flag = true;
			break;
		case 2:
			milkStock--;
			if (milkStock < 0)
				flag = true;
			break;
		case 3:
			mochaStock--;
			if (mochaStock < 0)
				flag = true;
			break;
		case 4:
			shotStock--;
			if (shotStock < 0)
				flag = true;
			break;
		case 5:
			whipStock--;
			if (whipStock < 0)
				flag = true;
			break;
		default:
			return false;
		}
	}
	if (flag)
	{
		addStockByIngredientsID(ingeredientsID);
		return false;
	}
	return true;
}

void StockManager::setCoffeeStock(int cs)
{
	coffeeStock = cs;
}

void StockManager::setMilkStock(int ms)
{
	milkStock = ms;
}

void StockManager::setMochaStock(int mks)
{
	mochaStock = mks;
}

void StockManager::setShotStock(int ss)
{
	shotStock = ss;
}

void StockManager::setWhipStock(int ws)
{
	whipStock = ws;
}

int StockManager::getCoffeeStock()
{
	return coffeeStock;
}

int StockManager::getMilkStock()
{
	return milkStock;
}

int StockManager::getMochaStock()
{
	return mochaStock;
}

int StockManager::getShotStock()
{
	return shotStock;
}

int StockManager::getWhipStock()
{
	return whipStock;
}

void StockManager::printStock()
{
	for(int i = 0 ; i < 20; i++)
	cout << '-';
	cout << endl;

	cout << "Àç·á ÀÜ°í È®ÀÎ " << endl << endl;
	cout << "Ä¿ÇÇÀÜ°í: " << coffeeStock << endl;
	cout << "¿ìÀ¯ÀÜ°í: " << milkStock << endl;
	cout << "¸ðÄ«ÀÜ°í: " << mochaStock << endl;
	cout << "¼¦ÀÜ°í: " << shotStock << endl;
	cout << "ÈÖÇÎÅ©¸²ÀÜ°í: " << whipStock << endl<< endl;

	for(int i = 0 ; i < 20; i++)
	cout << '-';
	cout << endl;


}

