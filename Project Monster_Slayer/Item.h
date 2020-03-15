#pragma once
#include <string>
class Item
{
protected:
	int weight;
	std::string name;
public:
	Item() {
		name = "Just an item";
		weight = 0;
	}
	Item(int weight, std::string description) {
		this->weight = weight;
		name = description;
	}

	bool operator ==(Item other) {
		return (this->name == other.name && this->weight == other.weight);
	}

	std::string description() {
		return name;
	}
};


