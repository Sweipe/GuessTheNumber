#include "class.h"
#include <iostream>
#include <string>
#include <Windows.h>

Game::Game() {
	guess_count = 4;
	attempts = 0;
	number = rand() % 100 + 1;
	win_count = 0;
}

void Game::Run() {


	int guess = 0;
	std::string input;

	std::cout << "Welcome to 'Number Guesser'!\nInput a number between 1 and 100.\n" <<
	"You have 4 attempts remaining.\nYour guess: ";

	while (true) {

		std::cin >> input;
		std::cout << typeid(input).name();

		if (guess < 1 || guess>100) {
			std::cout << guess;
			//std::cout << "Really?\nGuess again: ";
		}
		else if (guess < number) {
			attempts--;
			std::cout << "Greater >\n";
		}
		else if (guess > number) {
			attempts--;
			std::cout << "Lesser <\n";
		}
		else {
			std::cout << "Correct!";
			break;
		}
	}
}

void Game::Decrease() {
	if (attempts <= 0) {return;}
	attempts--;
	
	HANDLE outp = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(outp, { 9,3 });
	WriteConsole(outp, "d", 1, NULL, NULL);
}
