#ifndef GAME_H
#define GAME_H

class Game {

private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

public:
    // Constructor
    Game(int max);

    // Destructor
    ~Game();

    // Public method to play the game
    void play();

private:
    // Private method to print game result
    void printGameResult() const;

};

#endif // GAME_H
