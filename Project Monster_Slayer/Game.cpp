#include "Game.h"
#include <iostream>
#include <sstream>
#include <fstream>

//reads from a file to string
void print_from_file(std::string filename)
{
	std::string contents;
	std::ifstream in(filename, std::ios::in);
	if(in){
		std::cout << in.rdbuf();
		in.close();
	}
	else std::cout << "Error in reading file!";
}

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

Hero Game::characterCreation()
{
	print_from_file("../Files/pure_text/characterCreation.txt");
	return Hero();
}

void Game::run(){
	return;
}
