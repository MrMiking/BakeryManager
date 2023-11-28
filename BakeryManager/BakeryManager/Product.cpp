#include "Product.h"

void Product::ProductStats(string name, int quantity, float price) {
	this->name = name;
	this->quantity = quantity;
	this->price = price;
}

void Product::Add(int quantity) {
	this->quantity += quantity;
}