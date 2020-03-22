#pragma once
#include <string>
#include <fstream>

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
	friend std::ostream& operator<<(std::ostream& out, Item item) {
		out << item.name << '#' << item.weight << '#';
		return out;
	}

	std::string description() {
		return name;
	}
};


