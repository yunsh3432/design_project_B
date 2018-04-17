#pragma once
#include "CoffeeFactory.h"
#include "OrderTransactionManager.h"
#include "StockManager.h"
#include "SaleManager.h"
#include "ProductPriceCalculator.h"
class CounterFacade
{
public:
	CounterFacade();
	CounterFacade(OrderTransactionManager* _otm, StockManager* _sm, SaleManager* _slm);
	~CounterFacade();

	void order();
	void serveCoffee();
	void cancle();
	void menu();

	OrderTransactionManager* getOTM() { return otm; }
	StockManager* getSM() { return sm; }
	SaleManager* getSLM() { return slm; }

private:
	CoffeeFactory cf;
	ProductPriceCalculator ppc;
	OrderTransactionManager* otm;
	StockManager* sm;
	SaleManager* slm;
};

