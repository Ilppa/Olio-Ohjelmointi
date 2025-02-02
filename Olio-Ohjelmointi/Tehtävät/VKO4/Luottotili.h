#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include "Pankkitili.h"

class Luottotili : public Pankkitili {
private:
    double luottoraja;

public:
    Luottotili(double initialSaldo = 0);
    bool withdraw(double amount) override;
    bool deposit(double amount) override;
    void paivitaLuottoraja();  // Lisäämme julkisen funktion määrittelyn
    double getLuottoraja() const;
};

#endif // LUOTTOTILI_H
