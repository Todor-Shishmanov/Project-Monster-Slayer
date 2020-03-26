#pragma once
#include <vector>
#include <fstream>
#include "Unit.h"
#include "Potion.h"
class Hero : public Unit
{
private:
	Potion potion;
	std::vector<Item> backpack;
public:
	Hero() {
		Name = "This is just a Hero";
		HP = 10;
		level = 1;
		weapon = Weapon();
		potion = Potion();
		backpack = {};
	}
	Hero(std::string name, int lvl, int HP, Weapon weapon, Potion potion, std::vector<Item> vec_items) {
		Name = name;
		level = lvl;
		this->HP = HP;
		this->weapon = weapon;
		this->potion = potion;
		backpack = vec_items;
	}
	~Hero() {};

	friend std::ostream& operator <<(std::ostream& out, Hero hero);

	std::string name() {
		return Name;
	}
};