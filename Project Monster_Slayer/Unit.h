#pragma once
#include <vector>
#include <string>
#include "Item.h"

class Unit
{
protected:
	//cosmetics 
	std::string name;

	//todo classes and other stuff
	//...

	//gameplay
	int HP;
	int level;

	std::vector<Item> backpack;

public:
	Unit() {
		name = "This is just a Unit";
		HP = 10;
		level = 1;
		backpack = {};
	}
	Unit(std::string name, int lvl){
		this->name = name;
		level = lvl;
		HP = 10 * level;
		level = 1;
		backpack = {};
	}
	Unit(std::string name, int lvl, std::vector<Item> set_of_items) {
		this->name = name;
		level = lvl;
		HP = 10 * level;
		level = 1;
		
		backpack = set_of_items;
	}
	~Unit() {}

	bool operator ==(Unit other) {
		if (this->HP != other.HP || this->name != other.name || this->backpack.size() != other.backpack.size()) return false;
		bool flag = true;
		for (int i = 0; i < backpack.size(); i++) {
			if (this->backpack[i] != other.backpack[i]) return false;
		}
		return flag;
	}

	void changeHP(int change) {
		HP = HP + change;
	}
	bool isDead() {
		if (HP == 0) return true;
		return false;
	}
	std::string title() {
		return name;
	}

};

