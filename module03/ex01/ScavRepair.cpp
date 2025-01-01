#include "ScavTrap.hpp" 

void ScavRepair(ScavTrap &a, int amount_repaired);

void repair(ScavTrap &a, ScavTrap &b)
{
    std::string amount = "";
    std::string ScavTrap = "";

    while (ScavTrap != a.getName() && ScavTrap != b.getName())
    {
        std::cout << "Enter ScavTrap to be repaired: \n";
        std::getline(std::cin, ScavTrap);

        if (ScavTrap != a.getName() && ScavTrap != b.getName()) 
        {
            std::cout << "Invalid target. Please enter a valid name.\n";
            continue;
        }
        std::cout << "Enter amount to be repaired: \n";
        std::getline(std::cin, amount);

        unsigned int amount_repaired = 0;
        std::istringstream(amount) >> amount_repaired;

        if (ScavTrap == a.getName())
            a.ScavRepair(a, amount_repaired);
        else if (ScavTrap == b.getName())
           b.ScavRepair(b, amount_repaired);
    }
}

void ScavTrap::ScavRepair(ScavTrap &a, int amount_repaired)
{
    if (a.get_energy_points()>= 0 && a.get_hit_points() > 0)
    {
        a.beRepaired(amount_repaired);
        std::cout << PINK << "ScavTrap " << a.getName() << " is repaired for " << amount_repaired << " hit points" << std::endl << RESET;
    }
    if (a.get_energy_points() <= 0)
        std::cout << PINK << "ScavTrap " << a.getName() << " has no energy" << std::endl << RESET;
    if (a.get_hit_points() <= 0)
        std::cout << RED << "ScavTrap " << a.getName() << " is dead" << std::endl << RESET;
}