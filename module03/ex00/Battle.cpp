#include "ClapTrap.hpp"

void startCombat(ClapTrap &a, ClapTrap &b)
{
	std::string target = "";
	std::string amount = "";

	while (target != a.getName() && target != b.getName())
	{
		std::cout << "Enter target: \n";
		std::getline(std::cin, target);

		if (target != a.getName() && target != b.getName()) {
			std::cout << RED << "Invalid target. Please enter a valid name.\n" << RESET;
			continue;
		}
		std::cout << "Enter amount of damage: \n";
		std::getline(std::cin, amount);
		unsigned int damage = 0;
		std::istringstream(amount) >> damage;
		if (target == a.getName() && b.get_hit_points() > 0)
			a.performAttack(a, b, damage);
		else if (target == b.getName() && a.get_hit_points() > 0 )
			b.performAttack(b,a, damage);
	}
}


void ClapTrap::performAttack(ClapTrap &a, ClapTrap &b, int damage)
{
	if (b.get_energy_points() < 0)
	{
		std::cout << RED << "ClapTrap " << b.getName() << " has no energy" << std::endl << RESET;
			return;
	}
	b.get_damage(damage);
	b.attack(a.getName());
	a.takeDamage(damage);
}

void ClapTrap::get_damage(unsigned int amount)
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