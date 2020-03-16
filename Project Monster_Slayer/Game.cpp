#include "Game.h"
#include <iostream>
#include <fstream>

//reads from a file to console
void printStream(std::ifstream &in ,std::string content) {
	if (in) {
		std::getline(in, content, '#');
		std::cout << content;
		system("pause");
		system("CLS");
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
	//todo
}


Game::~Game()
{
	
}
void intro(std::ifstream &in, std::string content){
	printStream(in, content); //intro
	printStream(in, content); //meet the old pirate
	printStream(in, content); //the tide
	printStream(in, content);
	printStream(in, content);//nautilius story 1st part
	printStream(in, content);//nautilius story 2nd part
	printStream(in, content);//nautilius story 3rd part
	printStream(in, content);//Asking about a name
}
Hero Game::characterCreation()
{
	std::string name_answer = "";
	std::string content;

	std::ifstream in("../Files/pure_text/characterCreation.txt", std::ios::in);

	intro(in, content); //intro

	std::cin >> name_answer;
	if (name_answer.size() > 10 || name_answer.size() < 2) {
		while (name_answer.size() > 10 || name_answer.size() < 2); {
			std::cout << "Please repeat that?";
			std::cin >> name_answer;
		}
	}
	printStream(in, content);

	std::vector<Item> hero_backpack;
	Weapon hero_weapon = Weapon();
	Potion hero_potion = Potion();

	return Hero(name_answer, 1, hero_backpack, hero_weapon, hero_potion);
}

void Game::run(){
	return;
}
