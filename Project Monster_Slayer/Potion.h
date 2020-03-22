#pragma once
#include "Item.h"
class Potion : public Item
{
private:
	int heal;
	bool used;
public:
	Potion() {
		name = "This is just an empty vial";
		heal = 0;
		weight = 0;
		used = true;
	}
	Potion(int heal, std::string desc) {
		name = desc;
		this->heal = heal;
		weight = 1;
		used = false;
	}
	Potion(std::string name, int weight,int heal,bool used) {
		this->name = name;
		this->weight = weight;
		this->heal = heal;
		this->used = used;
	}
	~Potion() {};

	friend std::ostream& operator <<(std::ostream& out, Potion potion) {
		out << potion.name << '#' << potion.weight << '#' << potion.heal << '#' << potion.used << '#';
		return out;
	}

	int healing() {
		return heal;
	}
	bool isFull() {
		return !used;
	}
};

