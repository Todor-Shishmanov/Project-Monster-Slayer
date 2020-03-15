/*#pragma once
#include "Item.h"
class Potion : public Item
{
private:
	int heal;
	bool used;
public:
	Potion() {
		description = "This is just a Potion";
		heal = 1;
		weight = 1;
		used = true;
	}
	Potion(int heal, std::string desc) {
		description = desc;
		this->heal = heal;
		weight = 1;
		used = false;
	}
	~Potion() {};

	int healing() {
		return heal;
	}
	bool isFull() {
		return used;
	}
};*/

