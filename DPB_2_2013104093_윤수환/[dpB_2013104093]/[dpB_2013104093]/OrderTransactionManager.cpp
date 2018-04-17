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
		cout << "���� �ֹ��� �����ϴ�." << endl;
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
		cout << "���� �ִ�  �ֹ��� �����ϴ�." << endl;
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
		cout << "���� �ִ�  �ֹ��� �����ϴ�." << endl;
	}
	else
	{
		cout << "�ֹ��Ͻ� "; orderTransactions[0].printCoffeeInfo(); cout << "���Խ��ϴ�."<< endl;
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