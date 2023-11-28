#pragma once
#include "Product.h"
class Food
{
public:
	string name;
	int quantity;
	float price;

	void ProductStats(string name, int quantity, float price);
	void Add(int quantity);
};