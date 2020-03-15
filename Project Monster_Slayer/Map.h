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
			if (vec_coord == coord) return vec_units[i];
		}
		return T();
	}
};

template<class T>
class Room
{
private:
	std::string description;
	CoordTable<T> NPC;
	int Map[10][10] = {0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,0};
public:
	Room(std::string desc, CoordTable<T> NPC_list) {
		description = desc;
		NPC = NPC_list;
	}
	Room() {
		description = "This is just a Room";
		NPC = {};
	}
	~Room() {}

	//do it with a seed
	std::string describe() { 
		return description;
	} 
	void updateMap() {
		for (int i = 0; i < NPC.number_of_units; i++) {
			Map[NPC.vec_coord[i].coord_y][NPC.vec_coord[i].coord_x] = 1;
		}
	}

}; 

