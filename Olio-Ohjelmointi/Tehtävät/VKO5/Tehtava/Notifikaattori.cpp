#include "Notifikaattori.h"
#include <cstdlib>

Notifikaattori::Notifikaattori() : seuraajat(nullptr) {}

Notifikaattori::~Notifikaattori() {
    while (seuraajat) {
        Seuraaja* temp = seuraajat;
        seuraajat = seuraajat->next;
        delete temp;
    }
}

void Notifikaattori::lisaa(string nimi) {
    Seuraaja* uusi = new Seuraaja(nimi);
    uusi->next = seuraajat;
    seuraajat = uusi;
}

void Notifikaattori::poista(string nimi) {
    Seuraaja* nykyinen = seuraajat;
    Seuraaja* edellinen = nullptr;
    while (nykyinen) {
        if (nykyinen->getNimi() == nimi) {
            if (edellinen) {
                edellinen->next = nykyinen->next;
            } else {
                seuraajat = nykyinen->next;
            }
            delete nykyinen;
            return;
        }
        edellinen = nykyinen;
        nykyinen = nykyinen->next;
    }
}

void Notifikaattori::tulosta() {
    Seuraaja* temp = seuraajat;
    while (temp) {
        cout << temp->getNimi() << endl;
        temp = temp->next;
    }
}

void Notifikaattori::postita(const string& viesti) {
    Seuraaja* temp = seuraajat;
    while (temp) {
        temp->paivitys(viesti);
        temp = temp->next;
    }
}

void Notifikaattori::poistaSatunnainenSeuraaja() {
    if (!seuraajat || !seuraajat->next) return;

    Seuraaja* temp = seuraajat;
    int seuraajaIndex = rand() % 3;
    Seuraaja* edellinen = nullptr;
    for (int i = 0; i < seuraajaIndex; ++i) {
        edellinen = temp;
        temp = temp->next;
    }

    if (edellinen) {
        edellinen->next = temp->next;
    } else {
        seuraajat = temp->next;
    }

    delete temp;
}
