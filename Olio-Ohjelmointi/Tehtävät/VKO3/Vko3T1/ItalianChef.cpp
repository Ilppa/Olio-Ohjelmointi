#include "ItalianChef.h"

ItalianChef::ItalianChef(const std::string& name)
    : Chef(name) {
    std::cout << "How To Basic called for Yo MAMA " << chefName <<"...The password is - eggs" << std::endl;
}

ItalianChef::~ItalianChef() {
    std::cout << "How To Basic threw you like an egg " << chefName << std::endl;
}

int ItalianChef::makePizza(int flourAmount, int waterAmount) {
    int pizzasByFlour = flourAmount / 5;
    int pizzasByWater = waterAmount / 5;
    int pizzas = std::min(pizzasByFlour, pizzasByWater);
    return pizzas;
}

bool ItalianChef::askSecret(const std::string& pass, int flourAmount, int waterAmount) {
    if (pass == password) {
        std::cout << "Password correct. Making ..." << std::endl;
        int pizzas = makePizza(flourAmount, waterAmount);
        std::cout << "You made " << pizzas << " portions of Krabby Patty." << std::endl;
        return true;
    } else {
        std::cout << "Password incorrect. Cannot make Krabby Patty." << std::endl;
        return false;
    }
}
