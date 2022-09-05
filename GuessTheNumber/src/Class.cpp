#include "class.h"
#include <iostream>
#include <string>

Game::Game() {
}

void Game::Run() {
	int guess;
	int guess_count;
	int attempts;
	int win_count;

	int number = rand()%100+1;

	std::cout << "Welcome to 'Number Guesser'!\nInput a number between 1 and 100.\nYour guess: ";

	while (true) {

		std::cin >> guess;

		if (guess < 1 || guess>100) {
			std::cout << "Really?\nGuess again: ";
			continue;
		}
		else if (guess < number) {
			std::cout << "Greater >\n";
		}
		else if (guess > number) {
			std::cout << "Lesser <\n";
		}
		else {
			std::cout << "Correct!";
			break;
		}
	}
}
