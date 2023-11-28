#pragma once
#include "GlobalHeader.h"

class Product
{
public:
	string name;
	int quantity;
	float price;

	void ProductStats(string name, int quantity, float price);
	void Add(int quantity);
};