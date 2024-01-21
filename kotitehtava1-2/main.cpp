#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototype
void guessingGame();

int main() {

    // Call the guessingGame function
    guessingGame();

    return 0;
}

// Function definition for the guessing game
void guessingGame() {

    // Initialize the random number generator
    srand(time(0));

    // Generate a random number between 1 and 20
    int targetNumber = rand() % 20 + 1;

    // Player's guess
    int guess;

    cout << "Welcome to the guessing game! Guess the number between 1 and 20." << endl;

    do {

        cout << "Enter your guess: ";
        cin >> guess;

        // Check the relationship of the guess to the target number
        if (guess < targetNumber) {
            cout << "The number is higher. Try again!" << endl;
        } else if (guess > targetNumber) {
            cout << "The number is lower. Try again!" << endl;
        } else {
            cout << "Congratulations! You guessed it right." << endl;
        }

    } while (guess != targetNumber);
}
