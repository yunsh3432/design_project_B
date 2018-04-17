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
		cout << "점원 메뉴" << endl;
		cout << "1.주문받기 " << endl;
		cout << "2.커피제공 " << endl;
		cout << "3.주문취소 " << endl;
		cout << "4.되돌아가기 " << endl;
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
				cout << "다시 입력해 주세요" << endl;
		}
	}
}

void CounterFacade::order()
{
	
	for(int i = 0; i < 20; i++)
		cout << '-';
	cout << endl;
	cout << "주문 도와드리겠습니다!" << endl;
	cout << "기본 커피 아이디를 입력해 주세요" << endl;
	int coffeeID;
	cin >> coffeeID;//커피 아이디 입력
	Coffee* coffee = cf.makeCoffee(coffeeID);
	
	
	cout << "샷을 추가하시겠습니까? <Y/N>" << endl;
	char addshot;
	cin >> addshot;
	if(addshot == 'Y')
	{
		coffee = new ShotDecorator(coffee);
	}
	else
	{
	}
	
	cout << "휘핑크림을 추가하시겠습니까?<Y/N> " << endl;
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
		cout << "재고가 없습니다. " << endl;
		return;
	}
	else
	{
	}
	for(int i = 0; i < 20; i++)
		cout << '-';
	cout << endl;
	
	cout << "-----------------------------------------" << endl; 
	cout << "1. 매장에서 마시고 간다" << endl;
	cout << "2. 테이크아웃 한다" << endl;
	cout << "3. 쿠폰을 사용한다" << endl;
	cout << "할인 방법을 선택해주세요 : ";
	int type;
	cin >> type;
	while (!ppc.setDiscountAlgoritm(type))
	{
		cout << "잘못된 입력입니다." << endl;
	}
	int saled_price = ppc.discountPrice(coffee->getCost());
	cout << "최종 금액 : " << saled_price << endl;
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
	cout << "취소할 손님의 번호를 입력해 주세요:" ;
	int selec = -1;
	cin >> selec;
	Transaction* t = otm->getTransactionAt(selec);
	if (t == NULL)
	{
		cout << "유효한 주문이 아닙니다." << endl;
		return;
	}
	sm->addStockByIngredientsID(t->getCoffeeInfo());
	slm->addMoney(t->getprice());
	otm->deleteTransactionByIndex(selec);
	cout <<"주문이 취소되었습니다." << endl;
	cout <<"현재 주문 내역 :" << endl;
	otm->printTransactions();
}