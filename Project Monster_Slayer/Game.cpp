#include "Game.h"
#include <iostream>
#include <fstream>

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

void save(Hero hero) {
	std::string file_name = "../Files/Heroes/";
	file_name += hero.name();
	file_name += ".txt";
	std::ofstream saveHero(file_name.c_str(), std::ios::out);
	if (!saveHero) {
		std::cout << "saveHero not opening" << std::endl;;
	}
	else saveHero << hero;
	saveHero.close();
}

bool nameCheck(std::string name) {

	std::string content;
	std::ifstream check("../Files/Heroes/alreadyCreatedNames.txt", std::ios::in);
	while (!check.eof()) {
		std::getline(check, content, '#');
		if (name == content) {
			std::cout << "Name already taken" << std::endl;
			return false;
		}
	}
	check.close();
	int size = name.size();
	if (size > 10 || size < 2) {
		std::cout << "Name length must be bigger than 2 and smaller than 12" << std::endl;
		return false;
	}
	if (name[0] > 90 || name[0] < 65) {
		std::cout << "The first letter should be capital" << std::endl;
		return false;
	}
	for (int i = 1; i < size; i++) {
		if (name[i] > 122 || name[i] < 97) {
			std::cout << "Only the first letter should be capital" << std::endl;
			return false;
		}
	}
	return true;
}

//reads from a file to console
std::string printStream(std::ifstream &in) {
	if (in) {
		std::string content;
		std::getline(in, content, '#');
		return content;
	}
	else std::cout << "Error in reading file!";
	return "";
}

Game::Game(int seed)
{
	random_number = RNG(seed);
	main_hero = characterCreation();
	//todo
}


Game::~Game()
{
	
}


Hero Game::characterCreation()
{
	std::string name_answer = "";

	std::ifstream in("../Files/pure_text/characterCreation.txt", std::ios::in);
	std::cout << printStream(in);
	std::cin >> name_answer;
	while (!nameCheck(name_answer)) {
		std::cin >> name_answer;
	}

	std::ofstream saveName("../Files/Heroes/alreadyCreatedNames.txt", std::ios::app);
	saveName << name_answer << '#';
	saveName.close();

	std::vector<Item> hero_backpack = { Item(1,"A 'lucky kraken' silver coin") };
	Weapon hero_weapon = Weapon();
	Potion hero_potion = Potion();
	Hero hero(name_answer, 1, 10, hero_weapon, hero_potion, hero_backpack);

	save(hero);
	return hero;
}

void Game::run(){
	return;
}
