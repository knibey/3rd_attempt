#include <iostream>
#include <string_view>
#include "library.h"
#include "constants.h"
#include <string>
#include <utility>
#include <cstring>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cassert>
#include <cstdint>

class Monster {
public:
	enum MonsterType {
		MONSTER_DRAGON,
		MONSTER_GOBLIN,
		MONSTER_OGRE,
		MONSTER_ORC,
		MONSTER_SKELETON,
		MONSTER_TROLL,
		MONSTER_VAMPIRE,
		MONSTER_ZOMBIE,
		MAX_MONSTER_TYPES
	};

private:
	MonsterType m_type;
	std::string m_name;
	int m_hp;

public:

	Monster(MonsterType type, std::string name, int hp) : m_type(type), m_name(name), m_hp(hp) {}

	std::string getTypeString() const {
		switch (m_type) {
		case MONSTER_DRAGON:
			return "Dragon";
		case MONSTER_GOBLIN:
			return "Goblin";
		case MONSTER_OGRE:
			return "Ogre";
		case MONSTER_ORC:
			return "Orc";
		case MONSTER_SKELETON:
			return "Skeleton";
		case MONSTER_TROLL:
			return "Troll";
		case MONSTER_VAMPIRE:
			return "Vampire";
		case MONSTER_ZOMBIE:
			return "Zombie";
		default:
			return "Unknown";
		}
	}

	void print() const {
		std::cout << m_name << " is the " << getTypeString() << " that has " << m_hp << " health points.";
	}

};

class MonsterGenerator {
public:
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	static Monster generateMonster() {
		Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES-1));
		static std::string s_names[6] = {"Jack", "Anthony", "James", "Bob", "Donald", "Rick"};
		return Monster(type,s_names[getRandomNumber(0,5)], getRandomNumber(1, 100));
	}
};

int maintopic8_test3()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	Monster m = MonsterGenerator::generateMonster();
	m.print();

	return 0;
}
