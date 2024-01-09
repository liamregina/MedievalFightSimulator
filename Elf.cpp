#include <iostream>
#include "Elf.h"

using namespace std;

Elf :: Elf(const string & _name, double _health, double _attackStrength, string _family): Character(ELF, _name, _health, _attackStrength), family(_family) {}

void Elf :: Attack(Character & opponent) {

    double damageAmt = (health/MAX_HEALTH) * this->attackStrength;

    if (opponent.GetType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);

        if (opp.family == this->family) {
            cout << "Elf " << this->GetName() << " does not attack Elf " << opp.GetName() << "." << endl;
            cout << "They are both members of the " << this->family << " family." << endl;
            return;
        }
        else {
            cout << "Elf " << this->GetName() << " shoots an arrow at " << opp.GetName() << " --- TWANG!!" << endl;

            opp.Damage(damageAmt);

            cout << opp.GetName() << " takes " << damageAmt << " damage." << endl;
            return;
        }
    }
    else {
        cout << "Elf " << this->GetName() << " shoots an arrow at " << opponent.GetName() << " --- TWANG!!" << endl;

        opponent.Damage(damageAmt);

        cout << opponent.GetName() << " takes " << damageAmt << " damage." << endl;
        return;

        
    }
}
