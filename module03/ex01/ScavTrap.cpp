#include "ScavTrap.hpp"

void initialize_scavtrap_names(std::string &p1, std::string &p2)
{
    std::cout << "Enter name of first scavtrap: \n";
    std::getline(std::cin, p1);

    std::cout << "Enter name of second scavtrap: \n";
    std::getline(std::cin, p2);
}

void status(ScavTrap &a, ScavTrap &b)
{
    std::cout << PURPLE << a.getName() << " has " << a.get_hit_points() << " hit points and " << a.get_energy_points() << " energy points\n";
    std::cout << b.getName() << " has " << b.get_hit_points() << " hit points and " << b.get_energy_points() << " energy points\n" << RESET;
}

void ScavTrap::guardGate()
{
    std::cout << PINK << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl << RESET;
}