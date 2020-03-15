#pragma once
#include "Weapon.h"
class Unit
{
protected:
	//cosmetics 
	std::string Name;

	//todo classes and other stuff
	//...

	//gameplay
	int HP;
	int level;

	Weapon weapon;

public:
	Unit() {
		Name = "This is just a Unit";
		HP = 10;
		level = 1;
		weapon = Weapon();
	}
	Unit(std::string name, int lvl){
		Name = name;
		level = lvl;
		HP = 10 * level;
		weapon = Weapon();
	}
	~Unit() {}

	bool operator ==(Unit other) {
		return (this->Name == other.Name && this->level == other.level && this->weapon == other.weapon);
	}

	void changeHP(int change) {
		HP = HP + change;
	}
	bool isDead() {
		if (HP == 0) return true;
		return false;
	}
	std::string description() {
		std::string descr = Name;
		descr += " armed with ";
		descr += weapon.description() + ". ";
		return descr;
	}
};

