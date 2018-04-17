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

void ManagerFacade::orderIngredients()//��� ����
{
	cout << "��� ����" << endl;
	
	vector<int> id;
	int num;
	int price = 0;

	cout << "Ŀ�� ����" << endl;

	
	cin >> num;
	for (int i = 0; i < num; i++)
		id.push_back(1);
	price += num * 2000;

	cout << "���� ����" << endl;

	cin >> num;
	for (int i = 0; i < num; i++)
		id.push_back(2);
	price += num * 500;

	cout << "��ī ����" << endl;

	cin >> num;
	for (int i = 0; i < num; i++)
		id.push_back(3);
	price += num * 200;

	cout << "�� ����" << endl;
	
	cin >> num;
	for (int i = 0; i < num; i++)
		id.push_back(4);
	price += num * 200;

	cout << "����ũ��" << endl;
	
	cin >> num;
	for (int i = 0; i < num; i++)
		id.push_back(5);
	price += num * 100;

	if (slm->reduceMoney(price))
		sm->addStockByIngredientsID(id);
	else
	{
		cout << "�ں����� �����մϴ�." << endl;
		return;
	}

	printStockStatus();

}

void ManagerFacade::menu()
{
	for(int i = 0; i < 20; i++)
		cout << '-';
	cout  << endl;
	cout <<	"1.������" << endl;
	cout << "2.���Ȯ��" << endl;
	cout << "3.�ֹ� ���� Ȯ��" << endl;
	cout << "4.�ܿ� �ں��� Ȯ��" << endl;
	cout << "5.�ǵ��� ����" << endl;
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
	cout << "��� ����" << endl;
	sm->printStock();
}

void ManagerFacade::printTransactionStatus()
{
	if (otm->isOrderEmpty())
	{
		cout << "�ֹ� ������ �����ϴ�." << endl;
		return;
	}


	cout << "--------------���� �ֹ� ����--------------" << endl;
	otm->printTransactions();
	cout << endl << endl;
}
