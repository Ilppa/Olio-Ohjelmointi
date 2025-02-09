#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include "Seuraaja.h"

class Notifikaattori {
public:
    Notifikaattori();
    ~Notifikaattori();
    void lisaa(string nimi);
    void poista(string nimi);
    void tulosta();
    void postita(const string& viesti);

    void poistaSatunnainenSeuraaja();

private:
    Seuraaja* seuraajat;
};

#endif // NOTIFIKAATTORI_H
