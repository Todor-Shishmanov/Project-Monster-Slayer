#pragma once
#include "Hero.h"

class Game
{
private:
	std::vector<int> random_number;
	Hero main_hero;
public:

	Game(int seed);
	~Game();

	Hero characterCreation();
	void save();
	bool load(std::string hero_name);
	bool gameOver() {
		return 0;
	}
	int get_random_number() {
		int num = random_number[random_number.size()-1];
		random_number.pop_back();
		return num;
	}
	
	
	void run();
};

