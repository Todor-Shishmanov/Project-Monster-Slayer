#include "Hero.h";

std::ostream & operator<<(std::ostream & out, Hero hero){
	out << hero.Name << '#' << hero.level << '#' << hero.HP << '#' << hero.weapon << hero.potion;
	int size = hero.backpack.size();
	out << size << '#';
	for (int i = 0; i < size; i++) {
		out << hero.backpack[i];
	}
	return out;
}
