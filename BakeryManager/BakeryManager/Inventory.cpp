#include "Inventory.h"

void Inventory::Play(vector<Product*> ingredients, vector<Food*> foods, Player* player, float money) {
	this->ingredients = ingredients;
	this->foods = foods;
	this->player = player;
	player->AddMoney(money);
	BuyIngredients();
}

void Inventory::AddIngredient(Product* product, int quantity) {
	product->Add(quantity);
	player->RemoveMoney(product->price * quantity);
}

void Inventory::AddFood(Food* food, int quantity) {
	food->Add(quantity);
	player->RemoveMoney(food->price * quantity);
}

void Inventory::ShowIngredient() {
	for (int i = 0;i < this->ingredients.size();i++) {
		cout << this->ingredients[i]->name<<" | Quantity : ";
		cout << this->ingredients[i]->quantity<<endl;
	}
}

void Inventory::ShowFood() {
	for (int i = 0; i < this->foods.size(); i++) {
		cout << this->foods[i]->name << " | Quantity : ";
		cout << this->foods[i]->quantity << endl;
	}
}

void Inventory::BuyIngredients()
{
	if (player->money > 0) {
		system("CLS");
		cout << "Day " << day << endl;
		cout << "You have " << player->ShowMoney() << "$" << endl;
		cout << "Buy an ingredient :" << endl;
		for (int i = 0; i < ingredients.size(); i++) {
			cout << i + 1 << " - " << ingredients[i]->name << " " << ingredients[i]->price << "$" << endl;
		}
		int choice;
		cout << "Choice : ";
		cin >> choice;
		if (choice-1 >= 0 && choice - 1 < ingredients.size() && player->money >= ingredients[choice-1]->price) {
			int quantity = Quantity();
			if (quantity * ingredients[choice - 1]->price >= player->money) {
				AddIngredient(ingredients[choice - 1], player->money / ingredients[choice - 1]->price);
			}
			else {
				AddIngredient(ingredients[choice - 1], quantity);
			}
		}
		cout << "Continue ?" << endl;
		cout << "1 for continue" << endl;
		cout << "2 for cook" << endl;
		cin >> choice;
		if (choice == 1 && player->money >= 0) {
			BuyIngredients();
		}
		else {
			BuyFoods();
		}
	}
	cout << "You loose";
}

void Inventory::BuyFoods() {
	system("CLS");
	cout << "Day " << day << endl;
	cout << "You have " << player->ShowMoney() << "$" << endl;
	cout << "Cook :" << endl;
	for (int i = 0; i < foods.size(); i++) {
		cout << i + 1 << " - " << foods[i]->name << " " << foods[i]->price << "$" << endl;
	}
	int choice;
	cout << "Choice : ";
	cin >> choice;
	switch (choice) {
		case 1:
			DoBread();
			break;
		case 2:
			DoCheeseCake();
			break;
		case 3:
			DoOlivesCake();
			break;
	}
	cout << "Continue ?" << endl;
	cout << "1 for continue" << endl;
	cout << "2 for open shop" << endl;
	cin >> choice;
	if (choice == 1 && player->money >= 0) {
		BuyFoods();
	}
	else {
		SellAll();
	}
}

int Inventory::Quantity() {
	int quantity;
	cout << "Quantity : ";
	cin >> quantity;
	return quantity;
}

void Inventory::Choice() {
	cout << "You don't have enought ingredients for this recipe " << endl;
	int choice;
	cout << "try another recipe or pass the day ?" << endl;
	cout << "1 for try another recipe" << endl;
	cout << "2 for next day" << endl;
	cin >> choice;
	if (choice == 1) {
		BuyFoods();
	}
	else {
		SellAll();
	}
}

void Inventory::DoBread() {
	if (ingredients[0]->quantity > 0 && ingredients[4]->quantity > 0) {
		ingredients[0]->quantity -= 1;
		ingredients[4]->quantity -= 1;
		AddFood(foods[0], Quantity());
	}
	else {
		Choice();
	}
}

void Inventory::DoCheeseCake() {
	if (ingredients[0]->quantity > 0 
		&& ingredients[1]->quantity > 0 
		&& ingredients[3]->quantity > 0) {
		ingredients[0]->quantity -= 1;
		ingredients[1]->quantity -= 1;
		ingredients[3]->quantity -= 1;
		AddFood(foods[1], Quantity());
	}
	else {
		Choice();
	}
}

void Inventory::DoOlivesCake() {
	if (ingredients[0]->quantity > 0 
		&& ingredients[1]->quantity > 0
		&& ingredients[2]->quantity > 0
		&& ingredients[3]->quantity > 0
		&& ingredients[4]->quantity > 0) {
		ingredients[1]->quantity -= 1;
		ingredients[2]->quantity -= 1;
		ingredients[3]->quantity -= 1;
		ingredients[4]->quantity -= 1;
		AddFood(foods[2], Quantity());
	}
	else {
		Choice();
	}
}

void Inventory::SellAll() {
	int randomClient = player->GenerateRandomNumberBetween(5, 10);

	cout << randomClient << " Clients enter on your shop !"<<endl;
	
	for (int i = 0; i < randomClient; i++) {
		int randomFood = player->GenerateRandomNumberBetween(0, 2);
		int randomQuantity = player->GenerateRandomNumberBetween(1, 3);
		cout << "client " << i+1 << " want to buy " << randomQuantity << " " << foods[randomFood]->name << endl;
		if (foods[randomFood]->quantity > 0) {
			player->AddMoney(foods[randomFood]->price * randomQuantity);
			if (foods[randomFood]->quantity < randomQuantity) {
				cout << "client " << i+1 << " buy " << foods[randomFood]->quantity << " " << foods[randomFood]->name << endl;
				foods[randomFood]->quantity = 0;
			}
			else {
				foods[randomFood]->quantity -= randomQuantity;
				cout << "client " << i+1 << " buy " << randomQuantity << " " << foods[randomFood]->name << endl;
			}
		}
		else {
			cout << "You don't have any " << foods[randomFood]->name << endl;
		}
	}
	int choice;
	cout << "Next day ? " << endl;
	cin >> choice;
	day += 1;
	BuyIngredients();
}