#pragma once
#include "Food.h"
#include "Player.h"

class Inventory
{
public:
	vector<Product*> ingredients;
	vector<Food*> foods;
	Player* player;
	int day = 1;
	
	void Play(vector<Product*> ingredients, vector<Food*> foods, Player* player, float money);

	void AddIngredient(Product* product, int quantity);
	void AddFood(Food* food, int quantity);

	void ShowIngredient();
	void ShowFood();

	int Quantity();
	void Choice();

	void BuyIngredients();
	void BuyFoods();

	void DoBread();
	void DoCheeseCake();
	void DoOlivesCake();

	void SellAll();
};