#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

class Pankkitili {
private:
    string tilinumero;
    string tilinomistaja;
    double saldo;
    double laina;
    const double korko = 0.05;

public:
    static int tiliLaskuri;

    // Konstruktori
    Pankkitili(string omistaja, double alkuSaldo)
        : tilinomistaja(omistaja), saldo(alkuSaldo), laina(0.0) {
        tilinumero = "FI" + to_string(100000 + tiliLaskuri++);
        cout << "Luotu tili: " << tilinumero << " omistajalle: " << tilinomistaja
             << " saldo: " << saldo << " euroa.\n";
    }

    // Tulostaa tilitiedot
    void tulostaTilitiedot() const {
        cout << "Tilitiedot:\n";
        cout << "Tilinumero: " << tilinumero << "\n";
        cout << "Tilinomistaja: " << tilinomistaja << "\n";
        cout << "Saldo: " << saldo << " euroa\n";
        cout << "Laina: " << laina << " euroa\n";
    }

    // Uusi funktio tilinomistajan palauttamiseksi
    string getTilinomistaja() const {
        return tilinomistaja;
    }

    // Talletus
    void talleta(double summa) {
        saldo += summa;
        cout << "Talletettu " << summa << " euroa. Uusi saldo: " << saldo << " euroa.\n";
    }

    // Nosto
    void nosta(double summa) {
        if (saldo >= summa) {
            saldo -= summa;
            cout << "Nostettu " << summa << " euroa. Uusi saldo: " << saldo << " euroa.\n";
        } else {
            cout << "Nosto epäonnistui. Saldo ei riitä.\n";
        }
    }

    // Sijoittaminen
    void sijoita(double summa) {
        if (saldo < summa) {
            cout << "Sijoitus epäonnistui. Saldo ei riitä.\n";
            return;
        }
        saldo -= summa;

        double prosentti = (rand() % 1100) - 100; // Satunnainen tuotto -100% - +1000%
        double tuotto = summa * prosentti / 100;
        saldo += summa + tuotto;

        cout << "Sijoituksen tulos: " << prosentti << "%, tuotto: "
             << tuotto << " euroa. Uusi saldo: " << saldo << " euroa.\n";
    }

    // Lainan ottaminen
    void otaLainaa(double summa) {
        double maksimiLaina = laskeMaksimiLaina();
        if (summa > maksimiLaina) {
            cout << "Lainaa ei voi ottaa yli maksimirajan: " << maksimiLaina << " euroa.\n";
            return;
        }
        laina += summa;
        saldo += summa;
        cout << "Lainattu " << summa << " euroa. Uusi saldo: " << saldo << " euroa.\n";
    }

    // Lainan maksaminen
    void maksaLainaa(double summa) {
        double maksu = summa + summa * korko;
        if (saldo >= maksu) {
            saldo -= maksu;
            laina -= summa;
            cout << "Maksettu lainaa " << summa << " euroa (sis. korko: "
                 << maksu - summa << " euroa).\n";
        } else {
            cout << "Lainan maksaminen epäonnistui. Saldo ei riitä.\n";
        }
    }

    // Siirto tililtä toiselle
    bool siirra(Pankkitili &kohde, double summa) {
        if (saldo >= summa) {
            saldo -= summa;
            kohde.saldo += summa;
            cout << "Siirretty " << summa << " euroa tililtä "
                 << tilinumero << " tilille " << kohde.tilinumero << ".\n";
            return true;
        } else {
            cout << "Siirto epäonnistui. Saldo ei riitä.\n";
            return false;
        }
    }

    // Lasketaan maksimi lainamäärä
        double laskeMaksimiLaina() const {
        return saldo * 5; // Esimerkkinä: laina voi olla korkeintaan 5x saldo
    }
};

// Static member initialization
int Pankkitili::tiliLaskuri = 1;

void naytaValikko() {
    cout << "\nValitse toiminto:\n";
    cout << "1. Tulosta tilitiedot\n";
    cout << "2. Talleta rahaa\n";
    cout << "3. Nosta rahaa\n";
    cout << "4. Sijoita rahaa\n";
    cout << "5. Ota lainaa\n";
    cout << "6. Maksa lainaa\n";
    cout << "7. Siirra rahaa toiselle tilille\n";
    cout << "8. Poistu\n";
}

int main() {
    vector<Pankkitili> tilit;
    int maara;

    cout << "Montako tiliä haluat luoda? ";
    cin >> maara;

    for (int i = 0; i < maara; ++i) {
        string nimi;
        double saldo;
        cout << "Anna tilinomistajan nimi: ";
        cin >> nimi;
        cout << "Anna alkusumma: ";
        cin >> saldo;
        tilit.emplace_back(nimi, saldo);
    }

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    bool kaynnissa = true;
    while (kaynnissa) {
        string omistaja;
        cout << "\nAnna tilinomistajan nimi, jonka tiliä hallitaan: ";
        cin >> omistaja;

        Pankkitili *valittuTili = nullptr;

        // Etsitään oikea tili tilinomistajan nimen perusteella
        for (Pankkitili &tili : tilit) {
            if (tili.getTilinomistaja() == omistaja) {
                valittuTili = &tili;
                break;
            }
        }

        if (valittuTili) {
            naytaValikko();
            int valinta;
            cin >> valinta;
            switch (valinta) {
            case 1:
                valittuTili->tulostaTilitiedot();
                break;
            case 2: {
                double summa;
                cout << "Syötä talletettava summa: ";
                cin >> summa;
                valittuTili->talleta(summa);
                break;
            }
            case 3: {
                double summa;
                cout << "Syötä nostettava summa: ";
                cin >> summa;
                valittuTili->nosta(summa);
                break;
            }
            case 4: {
                double summa;
                cout << "Syötä sijoitettava summa: ";
                cin >> summa;
                valittuTili->sijoita(summa);
                break;
            }
            case 5: {
                double summa;
                cout << "Syötä lainasumma: ";
                cin >> summa;
                valittuTili->otaLainaa(summa);
                break;
            }
            case 6: {
                double summa;
                cout << "Syötä lainan takaisinmaksusumma: ";
                cin >> summa;
                valittuTili->maksaLainaa(summa);
                break;
            }
            case 7: {
                string kohdeNimi;
                double summa;
                cout << "Syötä siirron kohteen nimi: ";
                cin >> kohdeNimi;
                cout << "Syötä siirrettävä summa: ";
                cin >> summa;

                Pankkitili *kohdeTili = nullptr;

                // Etsitään kohdetili
                for (Pankkitili &kohde : tilit) {
                    if (kohde.getTilinomistaja() == kohdeNimi) {
                        kohdeTili = &kohde;
                        break;
                    }
                }

                if (kohdeTili) {
                    valittuTili->siirra(*kohdeTili, summa);
                } else {
                    cout << "Kohdetiliä ei löytynyt.\n";
                }
                break;
            }
            case 8:
                kaynnissa = false;
                break;
            default:
                cout << "Virheellinen valinta.\n";
            }
        } else {
            cout << "Tilinomistajaa ei löytynyt.\n";
        }
    }

    return 0;
}
