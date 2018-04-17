#include "OrderTransactionManager.h"
#include<iostream>
using namespace std;

OrderTransactionManager::OrderTransactionManager(void)
{
}


OrderTransactionManager::~OrderTransactionManager(void)
{
}

void OrderTransactionManager::addTransaction(Transaction t)
{
	orderTransactions.push_back(t);
}

Transaction OrderTransactionManager::getFrontTransaction()
{
	if(orderTransactions.size() == 0)
	{
		cout << "들어온 주문이 없습니다." << endl;
	}
	else
	{
		return orderTransactions[0];
	}
}

Transaction* OrderTransactionManager::getTransactionAt(int idx)
{
	if (orderTransactions.size())
	{
		if (0 <= idx && idx < orderTransactions.size())
		{
			return &orderTransactions[idx];
		}
	}
	return NULL;
}

void OrderTransactionManager::deleteTransactionByIndex(int idx)
{
	if(orderTransactions.size() == 0 || orderTransactions.size() < idx)
	{
		cout << "현재 있는  주문이 없습니다." << endl;
	}
	else
	{
		orderTransactions.erase(orderTransactions.begin()+idx);
	}
}

void OrderTransactionManager::deleteTransactionFromFront()
{
	if(orderTransactions.size() == 0)
	{
		cout << "현재 있는  주문이 없습니다." << endl;
	}
	else
	{
		cout << "주문하신 "; orderTransactions[0].printCoffeeInfo(); cout << "나왔습니다."<< endl;
		orderTransactions.erase(orderTransactions.begin());
	}
}

void OrderTransactionManager::printTransactions()
{
	for (int i = 0; i < orderTransactions.size(); i++)
	{
		cout << i << ". ";
		orderTransactions[i].printCoffeeInfo();
		cout << endl;
	}

}