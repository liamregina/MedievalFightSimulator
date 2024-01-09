#ifndef Wizard_H
#define Wizard_H

#include <string>
#include "Character.h"

using namespace std;

class Wizard : public Character {
    private:
        int rank;

    public: 
        Wizard(const string & _name, double _health, double _attackStrength, int _rank);
        void Attack(Character & opp);
        const int GetRank() {return rank;}
};

#endif