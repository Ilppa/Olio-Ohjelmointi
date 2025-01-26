#include "Chef.h"

Chef::Chef(const std::string& name) : chefName(name) {
    std::cout << "Chef Frank offered a job to " << chefName << std::endl;
}

Chef::~Chef() {
    std::cout << "Chef Frank called you out as a fraud - You can't even follow the recipe! Why don't you respect my art!!! " << chefName << std::endl;
}

std::string Chef::getName() const {
    return chefName;
}

int Chef::makeSalad(int ingredients) const {
    int portions = ingredients / 5;
    std::cout << chefName << " made " << portions << " Portions of Rat Quesadilla." << std::endl;
    return portions;
}

int Chef::makeSoup(int ingredients) const {
    int portions = ingredients / 3;
    std::cout << chefName << " made " << portions << " Portions of Human Ramen." << std::endl;
    return portions;
}
