#pragma once
#include "Transaction.h"
#include <vector>
#include <iostream>
using namespace std;
class OrderTransactionManager
{
public:
	OrderTransactionManager();
	~OrderTransactionManager();

	void addTransaction(Transaction t);
	Transaction getFrontTransaction();
	Transaction* getTransactionAt(int idx);
	void deleteTransactionFromFront();
	void deleteTransactionByIndex(int idx);
	void printTransactions();
	bool isOrderEmpty() { return !orderTransactions.size(); }

private:
	vector<Transaction> orderTransactions;
};

