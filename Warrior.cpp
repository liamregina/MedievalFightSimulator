#include <iostream>
#include "Warrior.h"

using namespace std;

Warrior :: Warrior(const string & _name, double _health, double _attackStrength, string _allegiance): Character(WARRIOR, _name, _health, _attackStrength), allegiance(_allegiance) {}

void Warrior :: Attack(Character & opponent) {

    double damageAmt = (health/MAX_HEALTH) * this->attackStrength;

    if (opponent.GetType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);

        if (opp.allegiance == this->allegiance) {
            cout << "Warrior " << this->GetName() << " does not attack Warrior " << opp.GetName() << "." << endl;
            cout << "They share an allegiance with " << this->allegiance << "." << endl;
            return;
        }
        else {
            cout << "Warrior " << this->GetName() << " attacks " << opp.GetName() << " --- SLASH!!" << endl;

            opp.Damage(damageAmt);

            cout << opp.GetName() << " takes " << damageAmt << " damage." << endl;
            return;
        }
    }
    else {
        cout << "Warrior " << this->GetName() << " attacks " << opponent.GetName() << " --- SLASH!!" << endl;

        opponent.Damage(damageAmt);

        cout << opponent.GetName() << " takes " << damageAmt << " damage." << endl;
        return;

        
    }
}

