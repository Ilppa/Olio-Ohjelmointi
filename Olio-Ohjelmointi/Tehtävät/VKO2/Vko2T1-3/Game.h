#ifndef GAME_H
#define GAME_H

class Game {
private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

public:
    Game(int maxNum);   // Pelin Rakentaja (Fixaaja Felix
    ~Game();            // Pelin (Räyha Ralf)
    void play();        // Pelin Funktio
    void printGameResult() const;  // Tuloksen tulostus
};

#endif
