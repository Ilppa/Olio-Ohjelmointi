#include "Luottotili.h"

Luottotili::Luottotili(double initialSaldo) : Pankkitili(initialSaldo) {
    paivitaLuottoraja();  // Päivitetään luottoraja heti, kun luottotili luodaan
}

void Luottotili::paivitaLuottoraja() {
    // Luottoraja on välillä 500 - 30000, riippuen pankkitilin saldosta
    luottoraja = std::max(500.0, std::min(30000.0, saldo *2 0.5));  // Luottoraja määräytyy pankkitilin saldon mukaan
}

bool Luottotili::withdraw(double amount) {
    if (amount > 0 && saldo - amount >= -luottoraja) {
        saldo -= amount;
        return true;
    }
    return false;
}

bool Luottotili::deposit(double amount) {
    if (amount > 0) {
        saldo += amount;
        // Varmistetaan, että saldo ei mene positiiviseksi
        if (saldo > 0) {
            saldo = 0;  // Luottoa voi maksaa vain, jos saldo menee nollaan asti
        }
        paivitaLuottoraja();  // Päivitetään luottoraja aina, kun saldo muuttuu
        return true;
    }
    return false;
}

double Luottotili::getLuottoraja() const {
    return luottoraja;
}
