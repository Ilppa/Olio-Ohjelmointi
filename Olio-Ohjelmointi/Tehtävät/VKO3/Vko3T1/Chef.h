#ifndef CHEF_H
#define CHEF_H

#include <string>
#include <iostream>

class Chef {
protected:
    std::string chefName;

public:
    Chef(const std::string& name);
    virtual ~Chef();

    std::string getName() const;

    int makeSalad(int ingredients) const;
    int makeSoup(int ingredients) const;
};

#endif
