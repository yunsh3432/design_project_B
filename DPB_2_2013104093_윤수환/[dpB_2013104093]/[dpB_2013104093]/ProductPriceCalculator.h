#pragma once
#include"DiscountAlgorithm.h"
class ProductPriceCalculator
{
public:
	ProductPriceCalculator();
	~ProductPriceCalculator();

	bool setDiscountAlgoritm(int discountAlgorithmID);
	int discountPrice(int price);

private:
	DiscountAlgorithm* dcalg;
};

