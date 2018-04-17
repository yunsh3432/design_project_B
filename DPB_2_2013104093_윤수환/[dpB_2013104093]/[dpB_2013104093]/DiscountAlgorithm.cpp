#include "DiscountAlgorithm.h"


DiscountAlgorithm::DiscountAlgorithm(void)
{
}


DiscountAlgorithm::~DiscountAlgorithm(void)
{
}

DiscountCoupon::DiscountCoupon(void)
{
}


DiscountCoupon::~DiscountCoupon(void)
{
}

int DiscountCoupon::discount(int price)
{
	return price*0 ;
}
DiscountDrinkInStore::DiscountDrinkInStore(void)
{
}


DiscountDrinkInStore::~DiscountDrinkInStore(void)
{
}

int DiscountDrinkInStore::discount(int price)
{
	return price;
}

DiscountTakeOut::DiscountTakeOut(void)
{
}


DiscountTakeOut::~DiscountTakeOut(void)
{
}

int DiscountTakeOut::discount(int price)
{
	return price*0.9 ;
}