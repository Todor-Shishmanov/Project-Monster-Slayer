#include "Game.h"
#include <iostream>

//creates a set of random numbers
std::vector<int> RNG(int seed){
	const int prime = 181;
	const int modulus = 2;
	std::vector<int> Z;
	Z.push_back(seed);
	for (int i = 0; i < prime; i++) {
		Z.push_back((Z[i] * modulus) % prime);
	}
	return Z;
}			


Game::Game(int seed)
{
	random_number = RNG(seed);

}


Game::~Game()
{
	
}
