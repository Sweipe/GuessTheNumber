#include "class.h"
#include <iostream>
#include <string>
#include <Windows.h>

Game::Game() {
	guess_count = 10;
	attempts = 0;
	srand((unsigned)time(0));
	number = rand() % 100 + 1;
	win_count = 0;
}

void Game::Run() {

	int exit_flag = 1;
	int guess = 0;
	std::string input;

	std::cout << "Welcome to 'Number Guesser'!\nInput a number between 1 and 100.\n" <<
	"You have "<<guess_count<<" attempts remaining.\nYour guess: ";
	while (exit_flag == 1) {
		while (true) {

			std::cin >> guess;

			if (attempts >= guess_count) {
				std::cout << "You have no attempts remaining, thus you've failed.\n";
				exit_flag = 0;
				break;
			}
			else if (guess < 1 || guess>100) {
				std::cout << "Really?\nGuess again: ";
			}
			else if (guess < number) {
				attempts++;
				std::cout << "Greater >\n";
			}
			else if (guess > number) {
				attempts++;
				std::cout << "Lesser <\n";
			}
			else {
				win_count++;
				attempts = 0;
				std::cout << "Correct!\nYour Current score is " << win_count <<
				"\nYou have " << guess_count << " attempts remaining.\nYour guess: ";
				number = rand() % 100 + 1;
			}
		}
	}
}
