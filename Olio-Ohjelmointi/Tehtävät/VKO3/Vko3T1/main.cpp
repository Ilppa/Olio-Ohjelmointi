#include "Chef.h"
#include "ItalianChef.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string chefName;
    string italianChefName;
    int saladIngredients, soupIngredients;
    int flour, water;
    string userPassword;

    cout << "Enter name for the Chef: ";
    cin >> chefName;

    Chef chef(chefName);

    cout << "Enter the number of ingredients for Rat Quesadillas: ";
    cin >> saladIngredients;
    chef.makeSalad(saladIngredients);

    cout << "Enter the number of ingredients for Human Ramen: ";
    cin >> soupIngredients;
    chef.makeSoup(soupIngredients);

    cout << "\nEnter name for the Italian Chef: ";
    cin >> italianChefName;

    ItalianChef italianChef(italianChefName);

    cout << "Enter password to make Krabby Patty: ";
    cin >> userPassword;

    cout << "Enter the amount of  Pickles for Krabby Patty: ";
    cin >> flour;

    cout << "Enter the amount of Eggs for Krabby Patty: ";
    cin >> water;

    italianChef.askSecret(userPassword, flour, water);

    return 0;
}
