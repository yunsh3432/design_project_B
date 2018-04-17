#pragma once
#include <vector>
using namespace std;
class Transaction
{
public:
	Transaction();
	~Transaction();
	Transaction(vector<int> oc, int _price);
	vector<int> getorderedCoffeeinfo();
	vector<int> getCoffeeInfo() { return orderedCoffeeInfo; }
	int getPrice() { return price; }
	void printCoffeeInfo();
	int getprice();
private:
	vector<int> orderedCoffeeInfo;
	int price;
};
