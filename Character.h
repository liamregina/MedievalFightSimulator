#include <string>
#include <iostream>

using namespace std;

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

enum HeroType {WARRIOR, ELF, WIZARD};

const double MAX_HEALTH = 100.0;

class Character {
 protected:
	HeroType type;
	string name;
	double health;
	double attackStrength;

 public:
 	Character(HeroType _type, const string & _name, double _health, double _attackStrength);
 	HeroType GetType() const;
 	const string & GetName() const;
 	int GetHealth() const;
 	void Damage(double d);
 	bool IsAlive() const;
 	virtual void Attack(Character & opp) = 0;
	void PrintDeathMessage() const;
	void ResetHealth() {health = MAX_HEALTH;}
 };

#endif