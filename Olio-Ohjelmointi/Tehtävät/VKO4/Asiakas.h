#ifndef ASIAKAS_H
#define ASIAKAS_H

#include "Pankkitili.h"
#include "Luottotili.h"

class Asiakas {
private:
    std::string nimi;
    Pankkitili pankkitili;
    Luottotili luottotili;

public:
    Asiakas(std::string n, double pankkiSaldo);
    void showSaldo() const;                // Näyttää saldot
    bool talletus(double amount);          // Talletus pankkitilille
    bool nosto(double amount);             // Nosto pankkitililtä
    bool luotonNosto(double amount);       // Luoton nosto
    bool luotonMaksu(double amount);       // Luoton maksaminen
    bool tiliSiirto(double amount, Asiakas &vastaanottaja);  // Siirto pankkitililtä toiselle asiakkaalle
    std::string getNimi() const;           // Palauttaa asiakkaan nimen
    Pankkitili& getPankkitili();           // Pankkitiliin pääsy
    Luottotili& getLuottotili();           // Luottotiliin pääsy
    void nollaaLuotto();                   // Nollaa asiakkaan luotto
};

#endif // ASIAKAS_H
