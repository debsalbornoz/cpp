#include "ClapTrap.hpp"

void initialize_names(std::string &p1, std::string &p2)
{
	std::cout << "Enter first name: \n";
	std::getline(std::cin, p1);

	std::cout << "Enter second name: \n";
	std::getline(std::cin, p2);
}

std::string ClapTrap::getName()
{
	return (name);
}

int ClapTrap::get_energy_points()
{
	return (energy_points);
}

int ClapTrap::get_hit_points()
{
	return (hit_points);
}

void getStatus(ClapTrap &a, ClapTrap &b)
{
	std::cout << PURPLE << a.getName() << " has " << a.get_hit_points() << " hit points and " << a.get_energy_points() << " energy points\n";
	std::cout << b.getName() << " has " << b.get_hit_points() << " hit points and " << b.get_energy_points() << " energy points\n" << RESET;
}

