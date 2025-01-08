#include <iostream>
#include <cstdlib>
#include <ctime>

// Funktio prototyyppi
int game(int maxnum);

int main() {
    char choice;

    do {
        int maxnum;

        std::cout << "Anna suurin mahdollinen luku, jota haluat arvailla: ";
        std::cin >> maxnum;

        if (maxnum < 1) {
            std::cout << "Suurimman luvun tulee olla vähintään 1." << std::endl;
            return 1; // Lopetetaan ohjelma virhetilanteessa
        }

        int attempts = game(maxnum); // Kutsutaan game-funktiota

        std::cout << "Peli päättyi. Arvauksia tehtiin yhteensä: " << attempts << std::endl;

        std::cout << "Haluatko pelata uudelleen? (x lopettaa, muu kirjain jatkaa): ";
        std::cin >> choice;

    } while (choice != 'x' && choice != 'X');

    std::cout << "Kiitos pelaamisesta!" << std::endl;
    return 0;
}

int game(int maxnum) {
    // Alustetaan satunnaislukugeneraattori aikaleimalla
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int randomNumber = std::rand() % maxnum + 1; // Satunnainen luku valilta 1-maxnum
    int guess = 0;                               // Pelaajan arvaus
    int attempts = 0;                            // Arvausten lukumäärän laskuri

    std::cout << "Arvaa tietokoneen arpoma luku valilta 1-" << maxnum << ": " << std::endl;

    // Toistetaan kunnes pelaaja arvaa oikein
    while (true) {
        std::cout << "Anna arvauksesi: ";
        std::cin >> guess;
        attempts++; // Lisätään arvausmäärää

        if (guess < 1 || guess > maxnum) {
            std::cout << "Arvauksen tulee olla valilta 1-" << maxnum << ". Yrita uudelleen." << std::endl;
            continue;
        }

        if (guess < randomNumber) {
            std::cout << "Luku on suurempi kuin " << guess << "." << std::endl;
        } else if (guess > randomNumber) {
            std::cout << "Luku on pienempi kuin " << guess << "." << std::endl;
        } else {
            std::cout << "Onneksi olkoon! Oikea vastaus on " << randomNumber << "!" << std::endl;
            break;
        }
    }

    return attempts; // Palautetaan arvausten lukumäärä
}
