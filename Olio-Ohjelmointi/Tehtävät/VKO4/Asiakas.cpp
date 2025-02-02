#include "Asiakas.h"

Asiakas::Asiakas(std::string n, double luottoraja) : nimi(n), luottotili(luottoraja) {}

void Asiakas::showSaldo() const {
    std::cout << nimi << " - Pankkitili: " << pankkitili.getBalance()
              << ", Luottotili: " << luottotili.getBalance() << "\n";
}

bool Asiakas::talletus(double amount) {
    return pankkitili.deposit(amount);
}

bool Asiakas::nosto(double amount) {
    return pankkitili.withdraw(amount);
}

bool Asiakas::luotonNosto(double amount) {
    return luottotili.withdraw(amount);
}

bool Asiakas::luotonMaksu(double amount) {
    return luottotili.deposit(amount);
}

bool Asiakas::tiliSiirto(double amount, Asiakas &vastaanottaja) {
    if (amount > 0 && pankkitili.withdraw(amount)) {
        return vastaanottaja.pankkitili.deposit(amount);
    }
    return false;
}
