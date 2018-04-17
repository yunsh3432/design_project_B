#include "Transaction.h"
#include<iostream>
using namespace std;


Transaction::Transaction(void)
{
}


Transaction::~Transaction(void)
{
}

Transaction::Transaction(vector<int> oc, int _price)
{
	orderedCoffeeInfo = oc;
	price = _price;
}
vector<int> Transaction::getorderedCoffeeinfo()
{
	return orderedCoffeeInfo;
}

int Transaction::getprice()
{
	return price;
}

void Transaction::printCoffeeInfo()
{
	for (int i = 0; i < orderedCoffeeInfo.size(); i++)
	{
		switch (orderedCoffeeInfo[i])
		{
		case 1:
			if (orderedCoffeeInfo.size() == 1)
				cout << "아메리카노 ";
			else if (orderedCoffeeInfo[1] != 2 && orderedCoffeeInfo[1] != 3)
				cout << "아메리카노 ";
			break;
		case 2:
			cout << "카푸치노 ";
			break;
		case 3:
			cout << "모카커피 ";
			break;
		case 4:
			cout << ", 샷 ";
			break;
		case 5:
			cout << ", 휘핑크림 ";
			break;
		default:
			return;
		}
	}
}