#pragma once
#include <vector>

class Game
{
private:
	std::vector<int> random_number;
	
public:

	Game(int seed);
	~Game();

	bool GameOver() {
		return 0;
	}
	int get_random_number() {
		int num = random_number[random_number.size()-1];
		random_number.pop_back();
		return num;
	}
};

