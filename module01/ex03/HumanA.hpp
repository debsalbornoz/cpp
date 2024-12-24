#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
    private:
        Weapon &_weapon;
        std::string _name;
    public:
        HumanA(std::string name, Weapon &_weapon);
        ~HumanA();
        void attack();
};

#endif