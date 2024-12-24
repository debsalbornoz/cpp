#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) :  _weapon(NULL), _name(name) {}
HumanB::~HumanB() {}

void HumanB::attack() {
    if (_weapon) {
        std::cout << _name << " attacks with their " << _weapon->getType() << "\n";
    } else {
        std::cout << _name << " has no weapon\n";
    }
}

void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}
