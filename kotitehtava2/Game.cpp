#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Constructor definition
Game::Game(int max) : maxNumber(max), numOfGuesses(0) {
    srand(time(0));
    randomNumber = (rand() % maxNumber) + 1;
    cout << "Welcome to the guessing game! Guess the number between 1 and " << maxNumber << "." << endl;
}

// Destructor definition
Game::~Game() {
    cout << "Object cleared from stack memory" << endl;
}

// Public method definition to play the game
void Game::play() {
    bool stayInLoop = true;

    while (stayInLoop) {
        cout << "Give your guess between 1-" << maxNumber << endl;

        // Pyydä pelaajan arvausta vasta tässä vaiheessa
        cin >> playerGuess;

        // Käsittele virheellinen syöte
        if (cin.fail() || playerGuess <= 0 || playerGuess > maxNumber) {
            cout << "Invalid input. Enter a valid integer guess between 1 and " << maxNumber << ": ";
        } else {
            numOfGuesses++;

            if (playerGuess == randomNumber) {
                cout << "Congratulations! You guessed it right." << endl;
                stayInLoop = false;
            } else {
                cout << (playerGuess < randomNumber ? "Your guess is too small." : "Your guess is too large.") << endl;
            }
        }


    }

    printGameResult();
}

// Private method definition to print game result
void Game::printGameResult() const {
    cout << "Game over! The correct number was: " << randomNumber << endl;
    cout << "Total guesses: " << numOfGuesses << endl;
}

