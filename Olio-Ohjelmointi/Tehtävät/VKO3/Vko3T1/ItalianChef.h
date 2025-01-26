#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include "Chef.h"
#include <string>
#include <iostream>
#include <algorithm>

class ItalianChef : public Chef {
private:
    std::string password = "eggs";
    int makePizza(int flourAmount, int waterAmount);

public:
    ItalianChef(const std::string& name);
    ~ItalianChef();

    bool askSecret(const std::string& pass, int flourAmount, int waterAmount);
};

#endif
