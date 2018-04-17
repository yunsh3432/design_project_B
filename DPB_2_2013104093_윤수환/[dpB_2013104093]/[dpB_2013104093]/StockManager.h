#pragma once
#include <vector>
#include <iostream>
using namespace std;
class StockManager
{
public:
	StockManager(void);
	~StockManager(void);
	bool addStockByIngredientsID(vector<int> ingredientsID);
	bool reduceStockByIngredientsID(vector<int> ingredientsID);

	void setCoffeeStock(int cs);
	void setMilkStock(int ms);
	void setMochaStock(int mks);
	void setShotStock(int ss);
	void setWhipStock(int ws);

	int getCoffeeStock();
	int getMilkStock();
	int getMochaStock();
	int getShotStock();
	int getWhipStock();

	void printStock();
	
private:
	int coffeeStock;
	int milkStock;
	int mochaStock;
	int shotStock;
	int whipStock;

};

