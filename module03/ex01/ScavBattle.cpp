#include "ScavTrap.hpp"

void ScavTrap::attack(const std::string& target)
{
    energy_points -= 1;
    std::cout << GREEN << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl << RESET;
}

void battle(ScavTrap &a, ScavTrap &b)
{
    std::string target = "";
    std::string amount = "";

    while (target != a.getName() && target != b.getName())
    {
        std::cout << "Enter target: \n";
        std::getline(std::cin, target);

        if (target != a.getName() && target != b.getName())
        {
            std::cout << RED << "Invalid target. Please enter a valid name.\n" << RESET;
            continue;
        }
        if (target == a.getName() && b.get_hit_points() > 0)
            a.ScavBattle(b,a);
        else if (target == b.getName() && a.get_hit_points() > 0 )
            b.ScavBattle(a,b);
    }
}

void ScavTrap::ScavBattle(ScavTrap &attacker, ScavTrap &target)
{
    if (attacker.get_energy_points() <= 0)
    {
        std::cout << RED << "ScavTrap " << attacker.getName() << " has no energy" << std::endl << RESET;
        return;
    }
    else
        attacker.attack(target.getName());
    if (target.get_hit_points() <= 0)
        std::cout << RED << "ScavTrap " << name << " is dead" << std::endl << RESET;
    else
    {
        target.takeDamage(attacker.get_damage());
        if (target.get_hit_points() <= 0)
            std::cout << RED << "ScavTrap " << name << " is dead" << std::endl << RESET;
        else
            std::cout << YELLOW << "ScavTrap " << name << " takes " << attacker.get_damage() << " points of damage" << std::endl << RESET;
    }
}