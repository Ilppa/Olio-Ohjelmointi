#include "Asiakas.h"

Asiakas::Asiakas(std::string n, double pankkiSaldo)
    : nimi(n), pankkitili(pankkiSaldo), luottotili() {  // Luottotilin saldo aluksi nolla
}

void Asiakas::showSaldo() const {
    std::cout << nimi << " - Pankkitili: " << pankkitili.getBalance()
    << ", Luottotili: " << luottotili.getBalance() << " (Luottoraja: "
    << luottotili.getLuottoraja() << ")\n";
}


bool Asiakas::talletus(double amount) { return pankkitili.deposit(amount); }
bool Asiakas::nosto(double amount) { return pankkitili.withdraw(amount); }

bool Asiakas::luotonNosto(double amount) {
    if (luottotili.withdraw(amount)) {
        pankkitili.deposit(amount);  // Siirretään nostettu summa pankkitilille
        return true;
    }
    return false;
}

bool Asiakas::luotonMaksu(double amount) {
    if (amount > 0 && pankkitili.withdraw(amount)) {  // Vähennetään summa pankkitililtä
        return luottotili.deposit(amount);  // Maksetaan summa luottotilille
    }
    return false;
}


bool Asiakas::tiliSiirto(double amount, Asiakas &vastaanottaja) {
    if (amount > 0 && pankkitili.withdraw(amount)) {
        return vastaanottaja.pankkitili.deposit(amount);
    }
    return false;
}

std::string Asiakas::getNimi() const {
    return nimi;
}

Pankkitili& Asiakas::getPankkitili() {
    return pankkitili;
}

Luottotili& Asiakas::getLuottotili() {
    return luottotili;
}

void Asiakas::nollaaLuotto() {
    luottotili.deposit(luottotili.getBalance());  // Nollaa luottotilin saldon
}

