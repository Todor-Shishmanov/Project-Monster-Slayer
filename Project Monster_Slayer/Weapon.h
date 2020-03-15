#pragma once
#include "Item.h"
class Weapon: public Item
{
private:
	int damage;
	int broken_curr;
	int broken_max;
public:
	Weapon() {
		name = "Fists";
		weight = 0;
		damage = 1;
		broken_curr = 0;
		broken_max = -1;
	}
	Weapon(int weight, int damage, std::string item_name) {
		name = item_name;
		this->weight = weight;
		this->damage = damage;
		broken_curr = 0;
		broken_max = (10 * weight) - damage;
	}
	~Weapon() {};

	bool operator ==(Weapon other) {
		return (this->name == other.name && this->weight == other.weight && this->damage == other.damage 
			&& this->broken_curr == other.broken_curr && this->broken_max == other.broken_max);
	}

	int getDmg() {
		return damage;
	}
	bool isBroken() {
		return (broken_curr == broken_max);
	}
	void repair() {
		broken_curr = 0;
	}
	
};

