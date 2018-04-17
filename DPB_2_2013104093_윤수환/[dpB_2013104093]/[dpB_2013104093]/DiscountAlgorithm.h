#pragma once
class DiscountAlgorithm
{
public:
	DiscountAlgorithm(void);
	~DiscountAlgorithm(void);
	
	virtual int discount(int price) = 0;
};

class DiscountCoupon :
	public DiscountAlgorithm
{
public:
	DiscountCoupon(void);
	~DiscountCoupon(void);

	int discount(int price);
};

class DiscountDrinkInStore :
	public DiscountAlgorithm
{
public:
	DiscountDrinkInStore(void);
	~DiscountDrinkInStore(void);

	
	int discount(int price);
};

class DiscountTakeOut :
	public DiscountAlgorithm
{
public:
	DiscountTakeOut(void);
	~DiscountTakeOut(void);

	int discount(int price);
};

