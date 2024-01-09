#ifndef Warrior_H
#define Warrior_H

#include <string>
#include "Character.h"

using namespace std;

class Warrior : public Character {
    private:
        string allegiance;

    public: 
        Warrior(const string & _name, double _health, double _attackStrength, string _allegiance);
        void Attack(Character & opp);
        const string GetAllegiance() {return allegiance;}
};

#endif