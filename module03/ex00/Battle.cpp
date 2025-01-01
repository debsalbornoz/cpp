#include "ClapTrap.hpp"

void battle(ClapTrap &a, ClapTrap &b)
{
    std::string claptrap = "";
    std::string amount = "";

    while (claptrap != a.getName() && claptrap != b.getName()) {
        std::cout << "Enter target: \n";
        std::getline(std::cin, claptrap);

        if (claptrap != a.getName() && claptrap != b.getName()) {
            std::cout << RED << "Invalid target. Please enter a valid name.\n" << RESET;
            continue;
        }

        std::cout << "Enter amount of damage: \n";
        std::getline(std::cin, amount);

        unsigned int damage = 0;
        std::istringstream(amount) >> damage;

        if (claptrap == a.getName() && a.get_hit_points() > 0)
        {
            if (b.get_energy_points() < 0)
            {
                std::cout << RED << "ClapTrap " << b.getName() << " has no energy" << std::endl << RESET;
                return;
            }
            b.get_attack_damage(damage);
            b.attack(a.getName());
            a.takeDamage(damage);
        }
        else if (claptrap == b.getName() && b.get_hit_points() > 0 )
        {
            if (a.get_energy_points() <= 0)
            {
                std::cout << RED << "ClapTrap " << a.getName() << " has no energy" << std::endl << RESET;
                return;
            }
            std::cout << a.get_energy_points() << std::endl;
            a.get_attack_damage(damage);
            a.attack(b.getName());
            b.takeDamage(damage);
        }
    }
}

void ClapTrap::get_attack_damage(unsigned int amount)
{
    attack_damage = amount;
}
void ClapTrap::attack(const std::string& target)
{
    if (hit_points <= 0)
        std::cout << RED <<"ClapTrap " << name << " can't attack because it is dead" << std::endl << RESET;
    if (energy_points > 0 && hit_points > 0)
    {
        energy_points -=1;
        std::cout << GREEN << "ClapTrap " << name << " atacks " << target;
        std::cout << ",causing " << attack_damage << " points of damage!" << std::endl << RESET;
    }
    else if (energy_points <= 0)
        std::cout << PURPLE <<"ClapTrap " << name << " has no energy" << std::endl << RESET;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hit_points -= amount;
    if (hit_points <= 0)
        std::cout << RED << "ClapTrap " << name << " is dead" << std::endl << RESET;
    else
        std::cout << YELLOW << "ClapTrap " << name << " takes " << amount << " points of damage" << std::endl << RESET;
}