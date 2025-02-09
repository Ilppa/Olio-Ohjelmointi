#include "Notifikaattori.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    Notifikaattori n;
    int seuraajienLkm;

    cout << "Luodaan notifikaattori." << endl;
    cout << "Kuinka monta seuraajaa haluat lisata? ";
    cin >> seuraajienLkm;
    cin.ignore();

    for (int i = 0; i < seuraajienLkm; ++i) {
        string nimi;
        cout << "Luodaan seuraaja: Anna seuraajan " << i + 1 << " nimi: ";
        getline(cin, nimi);
        n.lisaa(nimi);
    }

    cout << "Notifikaattori luo seuraajan." << endl;
    n.tulosta();

    cout << "Notifikaattori postaa viestin: Joku viesti olen 1" << endl;
    n.postita("Joku viesti olen 1");

    cout << "Seuraajat saivat viestin!" << endl;

    srand(time(0));

    while (seuraajienLkm > 1) {
        cout << "Notifikaattori poistaa seuraajan." << endl;

        n.poistaSatunnainenSeuraaja();
        seuraajienLkm--;

        cout << "Notifikaattori postaa viestin: vain " << seuraajienLkm << " on jaljella" << endl;
        n.postita("Vain " + to_string(seuraajienLkm) + " on jaljella!");

        cout << "Seuraajat saivat viestin!" << endl;
    }

    cout << "\nLopuksi vain yksi seuraaja on jaljella." << endl;
    cout << "Notifikaattori postaa viestin: Vain 1 on jaljella!" << endl;
    n.postita("Vain 1 on jaljella!");
    cout << "Seuraaja saivat viestin!" << endl;

    return 0;
}
