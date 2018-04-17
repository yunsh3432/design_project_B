#include "CounterFacade.h"
#include"Coffee.h"
#include"DiscountAlgorithm.h"



CounterFacade::CounterFacade(void)
{
	sm = new StockManager();
	slm = new SaleManager();
	otm = new OrderTransactionManager();
}


CounterFacade::~CounterFacade(void)
{
}

CounterFacade ::CounterFacade(OrderTransactionManager* _otm, StockManager* _sm, SaleManager* _slm)
{
	otm = _otm;
	sm = _sm;
	slm = _slm;
}
void CounterFacade::menu()
{
	while(1)
	{
		for(int i = 0 ; i < 20; i++)
			cout << '-';
		cout << endl;
		cout << "���� �޴�" << endl;
		cout << "1.�ֹ��ޱ� " << endl;
		cout << "2.Ŀ������ " << endl;
		cout << "3.�ֹ���� " << endl;
		cout << "4.�ǵ��ư��� " << endl;
		for(int i = 0 ; i < 20; i++)
			cout << '-';
		cout << endl;
		int selec;
		cout << "->";
		cin >> selec;
		switch(selec)
		{
			case 1:
				order();
				break;
			case 2:
				serveCoffee();
				break;
			case 3:
				cancle();
				break;
			case 4:
				return ;
				break;
			default:
				cout << "�ٽ� �Է��� �ּ���" << endl;
		}
	}
}

void CounterFacade::order()
{
	
	for(int i = 0; i < 20; i++)
		cout << '-';
	cout << endl;
	cout << "�ֹ� ���͵帮�ڽ��ϴ�!" << endl;
	cout << "�⺻ Ŀ�� ���̵� �Է��� �ּ���" << endl;
	int coffeeID;
	cin >> coffeeID;//Ŀ�� ���̵� �Է�
	Coffee* coffee = cf.makeCoffee(coffeeID);
	
	
	cout << "���� �߰��Ͻðڽ��ϱ�? <Y/N>" << endl;
	char addshot;
	cin >> addshot;
	if(addshot == 'Y')
	{
		coffee = new ShotDecorator(coffee);
	}
	else
	{
	}
	
	cout << "����ũ���� �߰��Ͻðڽ��ϱ�?<Y/N> " << endl;
	char addwhip;
	cin >> addwhip;
	if(addwhip == 'Y')
	{
		coffee = new WhipDecorator(coffee);
	}
	else
	{
	}
	if(!sm->reduceStockByIngredientsID(coffee->GetIngredientsID()))
	{
		cout << "��� �����ϴ�. " << endl;
		return;
	}
	else
	{
	}
	for(int i = 0; i < 20; i++)
		cout << '-';
	cout << endl;
	
	cout << "-----------------------------------------" << endl; 
	cout << "1. ���忡�� ���ð� ����" << endl;
	cout << "2. ����ũ�ƿ� �Ѵ�" << endl;
	cout << "3. ������ ����Ѵ�" << endl;
	cout << "���� ����� �������ּ��� : ";
	int type;
	cin >> type;
	while (!ppc.setDiscountAlgoritm(type))
	{
		cout << "�߸��� �Է��Դϴ�." << endl;
	}
	int saled_price = ppc.discountPrice(coffee->getCost());
	cout << "���� �ݾ� : " << saled_price << endl;
	slm->addMoney(saled_price);
	
	Transaction t(coffee->GetIngredientsID(), saled_price);
	otm->addTransaction(t);
}

void CounterFacade::serveCoffee()
{
	otm->printTransactions();
	otm->deleteTransactionFromFront();
}

void CounterFacade::cancle()
{
	otm->printTransactions();
	cout << "����� �մ��� ��ȣ�� �Է��� �ּ���:" ;
	int selec = -1;
	cin >> selec;
	Transaction* t = otm->getTransactionAt(selec);
	if (t == NULL)
	{
		cout << "��ȿ�� �ֹ��� �ƴմϴ�." << endl;
		return;
	}
	sm->addStockByIngredientsID(t->getCoffeeInfo());
	slm->addMoney(t->getprice());
	otm->deleteTransactionByIndex(selec);
	cout <<"�ֹ��� ��ҵǾ����ϴ�." << endl;
	cout <<"���� �ֹ� ���� :" << endl;
	otm->printTransactions();
}