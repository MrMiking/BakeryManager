#include "Food.h"

void Food::ProductStats(string name, int quantity, float price) {
	this->name = name;
	this->quantity = quantity;
	this->price = price;
}

void Food::Add(int quantity) {
	this->quantity += quantity;
}