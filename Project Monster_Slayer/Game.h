#pragma once
#include "Unit.h"

class Game
{
private:
	std::vector<int> random_number;
	Unit hero;
	
public:

	Game(int seed);
	~Game();

	bool GameOver() {
		return hero.isDead();
	}
	int get_random_number() {
		int num = random_number[random_number.size()-1];
		random_number.pop_back();
		return num;
	}
};

