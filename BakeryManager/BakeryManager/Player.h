#include <stdlib.h>
#include <time.h>
#pragma once
class Player
{
public:
	float money;

	void AddMoney(float money);
	void RemoveMoney(float money);
	float ShowMoney();

	void InitializeRandom();
	int GenerateRandomNumberBetween(int min, int max);
};