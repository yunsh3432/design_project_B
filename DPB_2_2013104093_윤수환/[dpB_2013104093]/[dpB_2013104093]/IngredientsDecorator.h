#pragma once
#include "Coffee.h"
class IngredientsDecorator :
	public Coffee
{
public:
	IngredientsDecorator();
	IngredientsDecorator(Coffee* coffee);
	~IngredientsDecorator();

protected:
	Coffee* pCoffee;
};

class WhipDecorator :
	public IngredientsDecorator
{
public:
	WhipDecorator(Coffee* c);
	~WhipDecorator();

	int getCost();
	vector<int> GetIngredientsID();
};

class ShotDecorator :
	public IngredientsDecorator
{
public:
	ShotDecorator(Coffee* c);
	~ShotDecorator();

	int getCost();
	vector<int> GetIngredientsID();
};

class MochaDecorator :
	public IngredientsDecorator
{
public:
	MochaDecorator(Coffee* c);
	~MochaDecorator();

	int getCost();
	vector<int> GetIngredientsID();
};

class MilkDecorator :
	public IngredientsDecorator
{
public:
	MilkDecorator(Coffee* c);
	~MilkDecorator();

	int getCost();
	vector<int> GetIngredientsID();
};

