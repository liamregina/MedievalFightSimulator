#include "Character.h"
#include <iostream>

using namespace std;

Character :: Character(HeroType _type, const string & _name, double _health, double _attackStrength): type(_type), name(_name), health(_health), attackStrength(_attackStrength) {}

HeroType Character :: GetType() const {return type;}

const string & Character :: GetName() const {return name;}

int Character :: GetHealth() const {
    int healthInt = static_cast<int>(health);
    return healthInt;
}

void Character :: Damage(double d) {
    health -= d;
}

bool Character :: IsAlive() const {return health > 0.0;}

void Character :: PrintDeathMessage() const {
    unsigned int deathMsgNumber = rand() % 9;
    
    if (deathMsgNumber == 1) {
        cout << this->GetName() << " died doing what they loved." << endl;
    }
    else if (deathMsgNumber == 2) {
        cout << this->GetName() << " should have got gud. RIP." << endl;
    }
    else if (deathMsgNumber == 3) {
        cout << this->GetName() << " has been set free from the chains of reality." << endl;
    }
    else if (deathMsgNumber == 4) {
        cout << this->GetName() << " fell victim to the hands of their opponent." << endl;
    }
    else if (deathMsgNumber == 5) {
        cout << this->GetName() << " ate too much cheese and could not tolerate the lactose." << endl;
    }
    else if (deathMsgNumber == 6) {
        cout << this->GetName() << " wasn't paying attention and got rekted." << endl;
    }
    else if (deathMsgNumber == 7) {
        cout << this->GetName() << " overslept, got too tired and fell asleep while in combat." << endl;
    }
    else { //deathMsgNumber == 8
        cout << this->GetName() << " died randomly for no reason." << endl;
    }
}  




