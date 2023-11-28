#include "Inventory.h"

int main()
{
    vector<Product*> ingredients;
    vector<Food*> foods;
    Inventory* inventory = new Inventory();

    Product* flour = new Product();
    Product* cheese = new Product();
    Product* olives = new Product();
    Product* eggs = new Product();
    Product* bakingPowder = new Product();

    Food* bread = new Food();
    Food* cheeseCake = new Food();
    Food* olivesCake = new Food();

    Player* player = new Player();

    flour->ProductStats("Flour", 0,0.5f);
    cheese->ProductStats("Cheese", 0, 1);
    olives->ProductStats("Olives", 0, 0.25f);
    eggs->ProductStats("Eggs", 0, 0.75f);
    bakingPowder->ProductStats("BakingPowder", 0, 0.25f);

    bread->ProductStats("Bread", 0, 1.5f);
    cheeseCake->ProductStats("CheeseCake", 0, 3.5f);
    olivesCake->ProductStats("OlivesCake", 0, 5);

    ingredients.push_back(flour);
    ingredients.push_back(cheese);
    ingredients.push_back(olives);
    ingredients.push_back(eggs);
    ingredients.push_back(bakingPowder);

    foods.push_back(bread);
    foods.push_back(cheeseCake);
    foods.push_back(olivesCake);

    inventory->Play(ingredients, foods, player, 30);
}