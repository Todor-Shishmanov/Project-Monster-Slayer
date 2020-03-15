/*#pragma once
#include "Item.h"
class Weapons: public Item
{
private:
	int damage;
	int broken_curr;
	int broken_max;
public:
	Weapons() {
		description = "This is just a Weapon";
		weight = 1;
		damage = 1;
		broken_curr = 0;
		broken_max = 0;
	}
	Weapons(int weight, int damage, std::string descr) {
		description = descr;
		this->weight = weight;
		this->damage = damage;
		broken_curr = 0;
		broken_max = (10 * weight) - damage;
	}
	~Weapons() {};

	int dmg() {
		return damage;
	}
	bool isBroken() {
		return (broken_curr == broken_max);
	}
	void repair() {
		broken_curr = 0;
	}
	
};*/

