#include "ClapTrap.hpp"

void restoreHealth(ClapTrap &a, ClapTrap &b)
{
	std::string amount = "";
	std::string claptrap = "";

	while (claptrap != a.getName() && claptrap != b.getName())
	{
		std::cout << "Enter claptrap to be repaired: \n";
		std::getline(std::cin, claptrap);

		if (claptrap != a.getName() && claptrap != b.getName()) 
		{
			std::cout << "Invalid target. Please enter a valid name.\n";
			continue;
		}
		std::cout << "Enter amount to be repaired: \n";
		std::getline(std::cin, amount);

		unsigned int amount_repaired = 0;
		std::istringstream(amount) >> amount_repaired;

		if (claptrap == a.getName())
			a.beRepaired(amount_repaired);
		else if (claptrap == b.getName())
			b.beRepaired(amount_repaired);
	}
}


void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points <= 0)
		std::cout << "Claptrap " << name << " can't be repaired because it is dead" << std::endl;
	if (energy_points > 0)
	{
		hit_points += amount;
		energy_points -= 1;
		std::cout << PINK << "ClapTrap " << name << " is repaired for " << amount << " hit points" << std::endl << RESET;
	}
	if (energy_points <= 0)
		std::cout << "ClapTrap " << name << " has no energy" << std::endl;
	if (hit_points <= 0)
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
}


