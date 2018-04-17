#include "CoffeeFactory.h"
#include<iostream>
using namespace std;

CoffeeFactory::CoffeeFactory(void)
{
}


CoffeeFactory::~CoffeeFactory(void)
{
}

Coffee* CoffeeFactory::makeCoffee(int coffeeID)
{
	Coffee* orderCoffee = new BaseCoffee();
	switch(coffeeID)
	{
		case 1:
			{
				return orderCoffee;
				break;
			}
		case 2:
			{
				orderCoffee = new MilkDecorator(orderCoffee);
				return orderCoffee;
				break;
			}
		case 3:
			{
				orderCoffee = new MochaDecorator(orderCoffee);
				return orderCoffee;
				break;
			}
		default:
			{
				cout << "없는 커피메뉴입니다." << endl;
			}
	}
}