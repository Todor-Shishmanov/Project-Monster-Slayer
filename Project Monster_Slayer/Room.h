#pragma once
#include <vector>

struct Coordinate {
	int coord_x;
	int coord_y;
	Coordinate(int x, int y) {
		coord_x = x;
		coord_y = y;
	}
	void operator=(Coordinate other) {
		this->coord_x = other.coord_x;
		this->coord_y = other.coord_y;
	}
	bool operator==(Coordinate other) {
		return (this->coord_x == other.coord_x && this->coord_y == other.coord_y);
	}
};

template<class T>
class CoordTable {
private:
	std::vector<Coordinate> vec_coord;
	std::vector<T> vec_units;
	int number_of_units;
public:
	CoordTable(){
		vec_coord = {};
		vec_units = {};
		number_of_units = 0;
	}

	void operator=(CoordTable<T> other){
		this->vec_units.clear();
		this->vec_coord.clear();
		for (int i = 0; i < other.number_of_units; i++) {
			this->vec_units.push_back(other.vec_units[i]);
			this->vec_coord.push_back(other.vec_coord[i]);
		}
		this->number_of_units = other.number_of_units;
	};

	int size() {
		return number_of_units;
	}
	void put_in_table(T template_unit, Coordinate coord) {
		vec_coord.push_back(coord);
		vec_units.push_back(template_unit);
		number_of_units++;
	}
	void remove_from_table(Coordinate coord) {
		for (int i = 0; i < number_of_units; i++) {
			if (vec_coord[i] == coord) {
				vec_coord.erase(vec_coord.begin() + i);
				vec_units.erase(vec_units.begin() + i);
			}
		}
	}
	void moveUnit(T template_unit, Coordinate coord) {
		for (int i = 0; i < number_of_units; i++) {
			if (vec_units[i] == template_unit) {
				vec_coord[i] = coord;
			}
		}
	}
	T getUnit(Coordinate coord)
	{
		for (int i = 0; i < number_of_units; i++) {
			if (vec_coord[i] == coord) return vec_units[i];
		}
		return T();
	}
	Coordinate getCoordByIndex(int index) {
		return vec_coord[index];
	}
};

template<class T>
class Room
{
private:
	std::string description;
	CoordTable<T> NPC_table;
	int Map[20][20];
public:
	Room(std::string desc, CoordTable<T> NPC_coord_list) {
		description = desc;
		NPC_table = NPC_coord_list;
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				Map[i][j] = 0;
			}
		}
		updateMap();
	}
	Room() {
		description = "This is just a Room";
		NPC_table = {};
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				Map[i][j] = 0;
			}
		}
	}
	~Room() {}

	//do it with a seed
	std::string describe() { 
		return description;
	} 
	void updateMap() {
		int NPC_table_size = NPC_table.size();
		for (int i = 0; i < NPC_table_size; i++) {
			Map[NPC_table.getCoordByIndex(i).coord_y][NPC_table.getCoordByIndex(i).coord_x] = 1;
		}
	}
}; 

