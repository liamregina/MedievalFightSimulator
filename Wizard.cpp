#include <iostream>
#include "Wizard.h"

using namespace std;

Wizard :: Wizard(const string & _name, double _health, double _attackStrength, int _rank): Character(WIZARD, _name, _health, _attackStrength), rank(_rank) {}

void Wizard :: Attack(Character & opponent) {

    double damageAmt = this->attackStrength;

    if (opponent.GetType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);

        damageAmt = this->attackStrength * (this->rank / 1.0 / opp.rank);

        cout << "Wizard " << this->GetName() << " attacks " << opp.GetName() << " --- POOF!!" << endl;

        opp.Damage(damageAmt);

        cout << opp.GetName() << " takes " << damageAmt << " damage." << endl;
        return;
    }
    else {
        cout << "Wizard " << this->GetName() << " attacks " << opponent.GetName() << " --- POOF!!" << endl;

        opponent.Damage(damageAmt);

        cout << opponent.GetName() << " takes " << damageAmt << " damage." << endl;
        return;
    }
}
