#include "Game.h"
#include <iostream>

int main() {
    char choice;

    do {
        int maxnum;
        std::cout << "Anna suurin luku, jota haluat arvailla: ";
        std::cin >> maxnum;

        if (maxnum < 1) {
            std::cout << "Suurimman luvun tulee olla vahintaan 1.\n";
            return 1;
        }

        Game game(maxnum);
        game.play();
        game.printGameResult();

        std::cout << "Haluatko pelata uudelleen? [Y] YES or NO [N]: \n ";
        std::cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    std::cout << "Kiitos pelaamisesta!\n";
    return 0;
}
