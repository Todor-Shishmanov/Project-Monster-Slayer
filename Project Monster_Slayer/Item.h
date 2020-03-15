#pragma once
#include <string>
class Item
{
protected:
	int weight;
	std::string description;
public:
	Item() {
		description = "Just an item";
		weight = 0;
	}

	bool operator !=(Item other) {
		return (this->description == other.description && this->weight == other.weight);
	}
	std::string describe() {
		return description;
	}
};


