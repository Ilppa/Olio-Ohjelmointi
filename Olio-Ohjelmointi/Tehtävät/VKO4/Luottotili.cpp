#include "Luottotili.h"

Luottotili::Luottotili(double raja) : luottoraja(raja) {}

bool Luottotili::withdraw(double amount) {
    if (amount > 0 && saldo - amount >= -luottoraja) {
        saldo -= amount;
        return true;
    }
    return false;
}

bool Luottotili::deposit(double amount) {
    if (amount > 0 && saldo + amount <= 0) {
        saldo += amount;
        return true;
    }
    return false;
}
