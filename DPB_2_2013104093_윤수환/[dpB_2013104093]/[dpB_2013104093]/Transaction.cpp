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
				cout << "�Ƹ޸�ī�� ";
			else if (orderedCoffeeInfo[1] != 2 && orderedCoffeeInfo[1] != 3)
				cout << "�Ƹ޸�ī�� ";
			break;
		case 2:
			cout << "īǪġ�� ";
			break;
		case 3:
			cout << "��īĿ�� ";
			break;
		case 4:
			cout << ", �� ";
			break;
		case 5:
			cout << ", ����ũ�� ";
			break;
		default:
			return;
		}
	}
}