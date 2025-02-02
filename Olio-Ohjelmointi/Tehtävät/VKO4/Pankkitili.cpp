#include "Pankkitili.h"

Pankkitili::Pankkitili(double initialSaldo) : saldo(initialSaldo) {}

Pankkitili::~Pankkitili() {}

bool Pankkitili::deposit(double amount) {
    if (amount > 0) {
        saldo += amount; // Lisää talletettu summa saldoon
        return true;
    }
    return false;
}

bool Pankkitili::withdraw(double amount) {
    if (amount > 0 && saldo >= amount) {
        saldo -= amount; // Vähentää nostetun summan saldosta
        return true;
    }
    return false;
}

double Pankkitili::getBalance() const {
    return saldo;
}
