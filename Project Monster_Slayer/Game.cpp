#include "Game.h"
#include <iostream>

//helpful
bool isNewGame() {
	std::cout << "Hello there good sir!" << std::endl << "Would you like a new adventure, or would you rather try to finish another?" << std::endl;
	std::string answer;
	std::cin >> answer;
	while (answer != "new" && answer != "old") {
		std::cout << "Answer with 'new' or 'old'" << std::endl;
		std::cin >> answer;
	}
	if (answer == "new")
		return 1;
	else {
		return 0;
	}
}
bool nameCheck(std::string name, std::string check_list_path) {

	std::string content;
	std::ifstream check(check_list_path.c_str(), std::ios::in);
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
//reads from a file to string
std::string streamToString(std::ifstream &in) {
	if (in) {
		std::string content;
		std::getline(in, content, '#');
		return content;
	}
	else std::cout << "Error in reading file!";
	return "";
}
//creates a set of random numbers
std::vector<int> RNG(int seed) {
	const int prime = 181;
	const int modulus = 2;
	std::vector<int> Z;
	Z.push_back(seed);
	for (int i = 0; i < prime; i++) {
		Z.push_back((Z[i] * modulus) % prime);
	}
	return Z;
}

void Game::save() {

	//save hero
	std::string file_name = "../Files/game/heroes/";
	file_name += main_hero.name();
	file_name += ".txt";
	std::ofstream saveHero(file_name.c_str(), std::ios::out);
	if (!saveHero) {
		std::cout << "Stream not opening: saving hero" << std::endl;;
	}
	else saveHero << main_hero;
	saveHero.close();

	//todo
}

bool Game::load(std::string heroName){

	//load hero
	std::string file_name = "../Files/game/heroes/";
	file_name += heroName;
	file_name += ".txt";
	std::ifstream loadHero(file_name, std::ios::in);
	if (loadHero) {
		const std::string hero_name = streamToString(loadHero);
		const int hero_level = stoi(streamToString(loadHero));
		const int hero_HP = stoi(streamToString(loadHero));

		const std::string weapon_name = streamToString(loadHero);
		const int weapon_weight = stoi(streamToString(loadHero));
		const int weapon_damage = stoi(streamToString(loadHero));
		const int weapon_broken_curr = stoi(streamToString(loadHero));
		const int weapon_broken_max = stoi(streamToString(loadHero));
		Weapon weapon(weapon_name, weapon_weight, weapon_damage, weapon_broken_curr, weapon_broken_max);

		const std::string potion_name = streamToString(loadHero);
		const int potion_weight = stoi(streamToString(loadHero));
		const int potion_heal = stoi(streamToString(loadHero));
		const bool potion_used = stoi(streamToString(loadHero));
		Potion potion(potion_name, potion_weight, potion_heal, potion_heal);

		const int backpack_size = stoi(streamToString(loadHero));
		std::vector<Item> hero_backpack;
		for (int i = 0; i < backpack_size; i++) {
			const std::string item_name = streamToString(loadHero);
			int item_weight = stoi(streamToString(loadHero));
			hero_backpack.push_back(Item(item_weight, item_name));
		}
		main_hero = Hero(hero_name, hero_level, hero_HP, weapon, potion, hero_backpack);
	}
	else return 0;
	loadHero.close();

	//set the random_number
	int new_seed;
	std::cout << "Enter a random number:" << std::endl;
	std::cin >> new_seed;
	random_number = RNG(new_seed);

	//todo
	return 1;
}


Game::Game(int seed){

	if (isNewGame()) {
		random_number = RNG(seed);
		main_hero = characterCreation();
		//todo
		save();
	}
	else {
		std::cout << "What is the name of the hero you played in the game?" << std::endl;
		std::string answer;
		std::cin >> answer;
		while (!load(answer)) {
			std::cout << "No hero found with this name. Try again or type 'New Game' to start a new game: " << std::endl;
			std::cin >> answer;
			if (answer == "New Game") {
				random_number = RNG(seed);
				main_hero = characterCreation();
				//todo
				save();
				break;
			}
		}
	}
	
}


Game::~Game(){
	
}


Hero Game::characterCreation(){
	std::string name_answer = "";

	std::ifstream in("../Files/pure_text/characterCreation.txt", std::ios::in);
	std::cout << streamToString(in);
	std::cin >> name_answer;
	while (!nameCheck(name_answer, "../Files/game/heroes/alreadyCreatedNames.txt")) {
		std::cin >> name_answer;
	}

	std::ofstream saveName("../Files/game/heroes/alreadyCreatedNames.txt", std::ios::app);
	saveName << name_answer << '#';
	saveName.close();

	std::vector<Item> hero_backpack = { Item(1,"A 'lucky kraken' silver coin") };
	Weapon hero_weapon = Weapon();
	Potion hero_potion = Potion();
	Hero hero(name_answer, 1, 10, hero_weapon, hero_potion, hero_backpack);

	return hero;
}



void Game::run(){
	return;
}

