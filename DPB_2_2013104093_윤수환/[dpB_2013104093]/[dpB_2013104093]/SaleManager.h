#pragma once
class SaleManager
{
public:
	SaleManager(void);
	~SaleManager(void);
	
	void changrprice(int price);
	int getprice();
	bool reduceMoney(int money);
	void addMoney(int money) { price += money; }
private:
	int price;
};

