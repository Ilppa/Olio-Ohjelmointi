#include "Asiakas.h"
#include <vector>
#include <limits>

void naytaValikko(Asiakas &asiakas) {
    int valinta;
    do {
        std::cout << "\nHallinnoi asiakasta: " << asiakas.getNimi() << "\n";
        std::cout << "1. Nayta saldot\n2. Talleta rahaa\n3. Nosta rahaa\n4. Nosta luottoa\n5. Maksa luottoa\n6. Poistu tililta\nValinta: ";
        std::cin >> valinta;

        double amount;
        switch (valinta) {
        case 1:
            asiakas.showSaldo();
            break;
        case 2:
            std::cout << "Summa: ";
            std::cin >> amount;
            asiakas.talletus(amount);
            break;
        case 3:
            std::cout << "Summa: ";
            std::cin >> amount;
            asiakas.nosto(amount);
            break;
        case 4:
            std::cout << "Summa: ";
            std::cin >> amount;
            asiakas.luotonNosto(amount);
            break;
        case 5:
            std::cout << "Summa: ";
            std::cin >> amount;
            asiakas.luotonMaksu(amount);
            break;
        case 6:
            std::cout << "Poistutaan tililta.\n";
            break;
        }
    } while (valinta != 6);
}

void adminToiminto(std::vector<Asiakas>& asiakkaat) {
    std::string salasana;
    std::cout << "Syota admin-salasana: ";
    std::cin >> salasana;

    if (salasana == "admin") {
        std::cout << "\nKaikki asiakkaat ja saldot:\n";
        for (auto& asiakas : asiakkaat) {
            asiakas.showSaldo();
        }

        // Anna adminille mahdollisuus nollata luottovelka
        std::string asiakasNimi;
        std::cout << "\nSyota asiakkaan nimi, jonka luotto nollataan (tai 'exit' poistuaksesi): ";
        std::cin >> asiakasNimi;

        if (asiakasNimi != "exit") {
            for (auto& asiakas : asiakkaat) {
                if (asiakas.getNimi() == asiakasNimi) {
                    asiakas.nollaaLuotto();
                    std::cout << "Luotto nollattu asiakkaalle " << asiakasNimi << ".\n";
                    break;
                }
            }
        }
    } else {
        std::cout << "Vaaras salasana.\n";
    }
}

int main() {
    std::vector<Asiakas> asiakkaat;
    int maara;
    std::cout << "Kuinka monta asiakasta luodaan? ";
    std::cin >> maara;
    for (int i = 0; i < maara; i++) {
        std::string nimi;
        double saldo;
        std::cout << "Anna asiakkaan nimi: ";
        std::cin >> nimi;
        std::cout << "Alkusaldo: ";
        std::cin >> saldo;
        asiakkaat.emplace_back(nimi, saldo);
    }
    while (true) {
        std::cout << "\nValitse toiminto: 1. Hallinnoi asiakasta 2. Admin-toiminto 3. Poistu\n";
        int valinta;
        std::cin >> valinta;

        if (valinta == 3) break;

        if (valinta == 2) {
            adminToiminto(asiakkaat);
        } else if (valinta == 1) {
            std::string nimi;
            std::cout << "\nAnna asiakkaan nimi, jonka tilille kirjaudutaan (tai 'exit' poistuaksesi): ";
            std::cin >> nimi;
            if (nimi == "exit") break;
            for (auto &asiakas : asiakkaat) {
                if (asiakas.getNimi() == nimi) {
                    naytaValikko(asiakas);
                    break;
                }
            }
        }
    }
    return 0;
}
