#pragma once
#include <string>
#include <vector>
using namespace std;

class Coffee
{
public:
	Coffee(void);
	~Coffee(void);

	
	virtual int getCost() = 0;
	virtual vector<int> GetIngredientsID() = 0;
};

class BaseCoffee :
	public Coffee
{
public:
	BaseCoffee(void);
	~BaseCoffee(void);
	
	int getCost();
	vector<int> GetIngredientsID();
};

