#include <iostream>
#include <sstream>
#include "Game.h"
#include "Room.h"
#include "Unit.h"
#include "Hero.h"

int main() {
	//testing

	Game test_game(10);

	/*Unit niki("Niki", 2);
	Unit ivo("Ivo", 3);

	Coordinate c_niki(1, 1);
	Coordinate c_ivo(2, 2);

	CoordTable<Unit> test;
	test.put_in_table(niki, c_niki);
	test.put_in_table(ivo, c_ivo);

	Room<Unit> test_room("My cute room", test);
	test_room.updateMap();
	*/
	
	test_game.load("Toto");
	system("pause");
	return 0;

}