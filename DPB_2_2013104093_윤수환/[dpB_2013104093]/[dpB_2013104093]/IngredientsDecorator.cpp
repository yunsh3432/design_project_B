#include "IngredientsDecorator.h"


IngredientsDecorator::IngredientsDecorator(void)
{
}

IngredientsDecorator::IngredientsDecorator(Coffee* coffee)
{
	pCoffee = coffee;
}

IngredientsDecorator::~IngredientsDecorator(void)
{
}
//¿ìÀ¯
MilkDecorator::MilkDecorator(Coffee* c)
{
	pCoffee = c;
}


MilkDecorator::~MilkDecorator(void)
{
}

int MilkDecorator::getCost()
{
	return 1000+pCoffee->getCost();
}

vector<int> MilkDecorator::GetIngredientsID()
{
	vector<int> ids = pCoffee->GetIngredientsID();
	ids.push_back(2);
	return ids;
}
//¸ðÄ«
MochaDecorator::MochaDecorator(Coffee* c)
{
	pCoffee = c;
}

MochaDecorator::~MochaDecorator(void)
{
}

int MochaDecorator::getCost()
{
	return 500+pCoffee->getCost();
}

vector<int> MochaDecorator::GetIngredientsID()
{
	vector<int> ids = pCoffee->GetIngredientsID();
	ids.push_back(3);
	return ids;
}

//¼¦
ShotDecorator::ShotDecorator(Coffee* c)
{
	pCoffee = c;
}


ShotDecorator::~ShotDecorator(void)
{
}

int ShotDecorator::getCost()
{
	return 500+pCoffee->getCost();
}

vector<int> ShotDecorator::GetIngredientsID()
{
	vector<int> ids = pCoffee->GetIngredientsID();
	ids.push_back(4);
	return ids;
}

//ÈÖÇÎÅ©¸²
WhipDecorator::WhipDecorator(Coffee* c)
{
	pCoffee = c;
}


WhipDecorator::~WhipDecorator(void)
{
}

int WhipDecorator::getCost()
{
	return pCoffee->getCost();
}


vector<int> WhipDecorator::GetIngredientsID()
{
	vector<int> ids = pCoffee->GetIngredientsID();
	ids.push_back(5);
	return ids;
}