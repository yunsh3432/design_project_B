#include "ManagerFacade.h"
#include<iostream>

using namespace std;

ManagerFacade::ManagerFacade(void)
{
}

ManagerFacade::ManagerFacade(OrderTransactionManager * _otm, StockManager* _sm, SaleManager* _slm)
{
	otm = _otm;
	sm = _sm;
	slm = _slm;
}
ManagerFacade::~ManagerFacade(void)
{
}

void ManagerFacade::orderIngredients()//재료 발주
{
	cout << "재료 발주" << endl;
	
	vector<int> id;
	int num;
	int price = 0;

	cout << "커피 개수" << endl;

	
	cin >> num;
	for (int i = 0; i < num; i++)
		id.push_back(1);
	price += num * 2000;

	cout << "우유 개수" << endl;

	cin >> num;
	for (int i = 0; i < num; i++)
		id.push_back(2);
	price += num * 500;

	cout << "모카 개수" << endl;

	cin >> num;
	for (int i = 0; i < num; i++)
		id.push_back(3);
	price += num * 200;

	cout << "샷 개수" << endl;
	
	cin >> num;
	for (int i = 0; i < num; i++)
		id.push_back(4);
	price += num * 200;

	cout << "휘핑크림" << endl;
	
	cin >> num;
	for (int i = 0; i < num; i++)
		id.push_back(5);
	price += num * 100;

	if (slm->reduceMoney(price))
		sm->addStockByIngredientsID(id);
	else
	{
		cout << "자본금이 부족합니다." << endl;
		return;
	}

	printStockStatus();

}

void ManagerFacade::menu()
{
	for(int i = 0; i < 20; i++)
		cout << '-';
	cout  << endl;
	cout <<	"1.재료발주" << endl;
	cout << "2.재고확인" << endl;
	cout << "3.주문 내역 확인" << endl;
	cout << "4.잔여 자본금 확인" << endl;
	cout << "5.되돌아 가기" << endl;
	for(int i = 0; i < 20; i++)
		cout << '-';
	cout  << endl;

	int selec;
	cin >> selec;
	switch(selec)
	{
	case 1:
		{
			orderIngredients();
			break;
		}
	case 2:
		{
			printStockStatus();
			break;
		}
	case 3:
		{
			printTransactionStatus();
			break;
		}
	case 4:
		{
			int price = slm->getprice();
			cout << price << endl;
			break;
		}
	case 5:
		{
			return;
		}
	}

}

void ManagerFacade::printStockStatus()
{
	cout << "재고 정보" << endl;
	sm->printStock();
}

void ManagerFacade::printTransactionStatus()
{
	if (otm->isOrderEmpty())
	{
		cout << "주문 내역이 없습니다." << endl;
		return;
	}


	cout << "--------------현재 주문 내역--------------" << endl;
	otm->printTransactions();
	cout << endl << endl;
}
