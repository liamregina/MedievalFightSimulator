#ifndef Elf_H
#define Elf_H

#include <string>
#include "Character.h"

using namespace std;

class Elf : public Character {
    private:
        string family;

    public: 
        Elf(const string & _name, double _health, double _attackStrength, string _family);
        void Attack(Character & opp);
        const string GetFamily() {return family;}
};

#endif