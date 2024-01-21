#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototype
int game(int maxnum);

int main() {

    // Call the game function with the maximum number
    int totalGuesses = game(40);

    // Print the total number of guesses
    cout << "Total guesses: " << totalGuesses << endl;

    return 0;
}

// Function definition
int game(int maxnum) {

    // Initialize the random number generator
    srand(time(0));

    // Generate a random number between 1 and maxnum
    int targetNumber = rand() % maxnum + 1;

    // Player's guess
    int guess;
    int guesses = 0;

    cout << "Welcome to the guessing game! Guess the number between 1 and " << maxnum << "." << endl;

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

        guesses++;

    } while (guess != targetNumber);

    return guesses;
}
