#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap &src);
        ~FragTrap(void);
        FragTrap &operator=(const FragTrap &src);
        void highFivesGuys(void);
        void attack(const std::string& target);
        void FragBattle(FragTrap &attacker, FragTrap &target);
        void FragRepair(FragTrap &a, int amount_repaired);
};

void initialize_names(std::string &p1, std::string &p2);
void battle(FragTrap &a, FragTrap &b);
void status(FragTrap &a, FragTrap &b);

#endif