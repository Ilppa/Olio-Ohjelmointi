#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game(int maxNum) : maxNumber(maxNum), numOfGuesses(0) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    randomNumber = std::rand() % maxNumber + 1;
    std::cout << "FIXAAJA FELIX: Objekti luotu suurimmalla arvolla " << maxNumber << ".\n";
}

Game::~Game() {
    std::cout << "RAYHA RALF: Muisti TUHOTTU.\n";
}

void Game::play() {
    int lowerBound = 1;
    int upperBound = maxNumber;

    std::cout << "Aloitetaan peli. Arvaa luku valilta " << lowerBound << " ja " << upperBound << ".\n";

    do {
        std::cout << "Anna arvauksesi valilta " << lowerBound << " - " << upperBound << ": ";
        std::cin >> playerGuess;
        numOfGuesses++;
        std::cout << "Pelaaja arvasi luvun " << playerGuess << "\n";

        if (playerGuess < lowerBound || playerGuess > upperBound) {
            std::cout << "Arvauksen tulee olla valilta " << lowerBound << " ja " << upperBound << ". Yrita uudelleen.\n";
            continue;
        }

        if (playerGuess < randomNumber) {
            std::cout << "Luku on suurempi.\n";
            lowerBound = playerGuess + 1;
        } else if (playerGuess > randomNumber) {
            std::cout << "Luku on pienempi.\n";
            upperBound = playerGuess - 1;
        } else {
            std::cout << "Onneksi olkoon! Oikea vastaus on " << randomNumber << ".\n";
            break;
        }
    } while (true);
}

void Game::printGameResult() const {
    std::cout << "Peli paattyi. Arvauksia tehtiin yhteensa: " << numOfGuesses << "\n";
    std::cout << "Oikea luku oli " << randomNumber << ", ja arvasit oikein " << numOfGuesses << " yrityksella.\n";
}
