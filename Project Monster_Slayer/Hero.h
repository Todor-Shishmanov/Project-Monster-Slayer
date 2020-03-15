#pragma once
#include <vector>
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
	Hero(std::string name, int lvl, std::vector<Item> vec_items, Weapon weapon, Potion potion) {
		Name = name;
		level = lvl;
		HP = 10 * level;
		this->weapon = weapon;
		this->potion = potion;
		backpack = vec_items;
	}
	~Hero() {};
};