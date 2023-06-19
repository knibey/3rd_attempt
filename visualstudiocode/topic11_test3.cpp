#include <iostream>
#include "library.h"

int getRandomNumber2(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature {
protected:
	std::string m_name;
	char m_symbol;
	int m_hp;
	int m_damage;
	int m_gold;
public:
	Creature(std::string name, char symbol, int hp, int damage, int gold)
		: m_name(name), m_symbol(symbol), m_hp(hp), m_damage(damage), m_gold(gold) {}

	const std::string& getName() {
		return m_name;
	}

	char getSymbol() {
		return m_symbol;
	}

	int getHealth() {
		return m_hp;
	}

	int getDamage() {
		return m_damage;
	}

	int getGold() {
		return m_gold;
	}

	void reduceHealth(int value) {
		m_hp -= value;
	}

	bool isDead() {
		if (m_hp == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void addGold(int value) {
		m_gold += value;
	}
};

class Player : public Creature {
private:
	int m_level = 1;
public:
	Player(std::string name) : Creature(name, '@', 10, 1, 0) {}

	void levelUp() {
		m_level += 1;
		m_damage += 1;
	}

	int getLevel() { return m_level; }
	bool hasWon() { return m_level == 20; }
};

class Monster : public Creature {
public:
	enum MONSTER_TYPE {
		TYPE_DRAGON,
		TYPE_ORC,
		TYPE_SLIME,
		MAX_TYPES
	};

	struct MonsterData {
		std::string name;
		char symbol;
		int health;
		int damage;
		int gold;
	};

	static MonsterData monsterData[Monster::MAX_TYPES];

	static Monster getRandomMonster()
	{
		int num = getRandomNumber2(0, MAX_TYPES - 1);
		return Monster(static_cast<MONSTER_TYPE>(num));
	}

	Monster(MONSTER_TYPE monster_type) : Creature(monsterData[monster_type].name, monsterData[monster_type].symbol, monsterData[monster_type].health, monsterData[monster_type].damage, monsterData[monster_type].gold) {}
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

void attackMonster(Monster& monster, Player& player) {
	if (player.isDead()) {
		return;
	}

	std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";

	monster.reduceHealth(player.getDamage());

	if (monster.isDead()) {
		std::cout << "You killed the " << monster.getName() << std::endl;
		player.levelUp();
		std::cout << "You're now level " << player.getLevel() << std::endl;
		std::cout << "You found " << monster.getGold() << " gold" << std::endl;
		player.addGold(monster.getGold());
	}
}

void attackPlayer(Monster& monster, Player& player) {
	if (monster.isDead()) {
		return;
	}

	std::cout << monster.getName() << " hitted you for " << player.getDamage() << " damage.\n";
	player.reduceHealth(monster.getDamage());
}

void fightMonster(Player& player) {
	Monster monster = Monster::getRandomMonster();
	std::cout << "A " << monster.getName() << " (" << monster.getSymbol() << ") was created.\n";
	std::cout << "You have encountered " << monster.getName() << " (" << monster.getSymbol() << ")." << std::endl;

	
	while (!monster.isDead() && !player.isDead()) {
		std::cout << "(R)un or (F)ight: " << std::endl;
		std::string pChoice = getStringFromUser();

		if (pChoice == "r" || pChoice == "R") {
			if (getRandomNumber2(1, 2) == 1) {
				std::cout << "You successfully fled" << std::endl;
				return;
			}
			else {
				std::cout << "You failed to flee" << std::endl;
				attackPlayer(monster, player);
				continue;
			}
		}

		if (pChoice == "f" || pChoice == "F") {
			attackMonster(monster, player);
			attackPlayer(monster, player);
		}
	}

}

int maintopic11_test3()
{
	srand(static_cast<unsigned int>(time(0))); // встановлюємо значення системного годинника в якості стартового значення
	rand(); // скидаємо перший результат

	std::cout << "Yo, whats your name?: ";
	std::string name = getStringFromUser();
	Player player(name);
	std::cout << "Welcome, " << player.getName() << std::endl;


	while (!player.isDead()) {
		fightMonster(player);
	}

	if (player.isDead()) {
		std::cout << "You lost the game with " << player.getGold() << " gold and " << player.getLevel() << " level" << std::endl;
	} else {
		std::cout << "You won the game with " << player.getGold() << " gold and " << player.getLevel() << " level" << std::endl;
	}

	return 0;
}