#pragma once

class Game {
public:
	int guess_count;
	int attempts;
	int number;
	int win_count;

	Game();
	void Run();
	void Decrease();
};