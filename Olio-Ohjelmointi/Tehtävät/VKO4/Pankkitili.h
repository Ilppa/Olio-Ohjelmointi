#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <iostream>
#include <string>

class Pankkitili {
protected:
    double saldo;

public:
    Pankkitili(double initialSaldo = 0);
    virtual ~Pankkitili();
    virtual bool deposit(double amount);  // Talletus
    virtual bool withdraw(double amount); // Nosto
    double getBalance() const;            // Pankkitilin saldo
};

#endif // PANKKITILI_H
