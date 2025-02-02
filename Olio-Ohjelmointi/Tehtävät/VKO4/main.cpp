#include "Asiakas.h"

int main() {
    Asiakas asiakas1("Matti", 500);
    Asiakas asiakas2("Teemu", 300);

    asiakas1.talletus(1000);
    asiakas1.nosto(200);
    asiakas1.luotonNosto(300);
    asiakas1.luotonMaksu(100);
    asiakas1.showSaldo();

    asiakas2.talletus(500);
    asiakas1.tiliSiirto(300, asiakas2);

    asiakas1.showSaldo();
    asiakas2.showSaldo();

    return 0;
}
