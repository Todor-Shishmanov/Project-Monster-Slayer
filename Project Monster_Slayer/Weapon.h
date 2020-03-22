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
	Weapon(std::string item_name, int weight, int damage) {
		name = item_name;
		this->weight = weight;
		this->damage = damage;
		broken_curr = 0;
		broken_max = (10 * weight) - damage;
	}
	Weapon(std::string name, int weight, int damage, int broken_curr, int breoken_max) {
		this->name = name;
		this->weight = weight;
		this->damage = damage;
		this->broken_curr = broken_curr;
		this->broken_max = broken_max;
	}
	~Weapon() {};

	bool operator ==(Weapon other) {
		return (this->name == other.name && this->weight == other.weight && this->damage == other.damage 
			&& this->broken_curr == other.broken_curr && this->broken_max == other.broken_max);
	}
	friend std::ostream& operator<<(std::ostream& out, Weapon weapon) {
		out << weapon.name << '#' << weapon.weight << '#' << weapon.damage << '#' << weapon.broken_curr << '#' << weapon.broken_max << '#';
		return out;
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

