#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Alustetaan satunnaislukugeneraattori aikaleimalla
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int randomNumber = std::rand() % 20 + 1;  // Satunnainen luku valilta 1-20
    int guess = 0;                            // Pelaajan arvaus

    std::cout << "Arvaa tietokoneen arpoma luku valilta 1-20: " << std::endl;

    // Toistetaan kunnes pelaaja arvaa oikein
    while (true) {
        std::cout << "Anna arvauksesi: ";
        std::cin >> guess;

        if (guess < 1 || guess > 20) {
            std::cout << "Arvauksen tulee olla valilta 1-20. Yrita uudelleen." << std::endl;
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

    return 0;
}
