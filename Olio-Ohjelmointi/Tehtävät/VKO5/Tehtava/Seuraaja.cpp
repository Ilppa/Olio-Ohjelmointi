#include "Seuraaja.h"

Seuraaja::Seuraaja(string nimi) : nimi(nimi), next(nullptr) {}

void Seuraaja::paivitys(const string& viesti) {
    cout << nimi << " sai viestin: " << viesti << endl;
}

string Seuraaja::getNimi() {
    return nimi;
}
