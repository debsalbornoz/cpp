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
			b.performAttack(a, b, damage);
		else if (target == b.getName() && a.get_hit_points() > 0 )
			a.performAttack(b,a, damage);
	}
}


void ClapTrap::performAttack(ClapTrap &target, ClapTrap &attacker, int damage)
{
	if (attacker.get_energy_points() < 0)
	{
		std::cout << RED << "ClapTrap " << attacker.getName() << " has no energy" << std::endl << RESET;
			return;
	}
	attacker.get_damage(damage);
	if (attacker.get_energy_points() > 0)
	{
		attacker.attack(target.getName());
		target.takeDamage(damage);
	}
	else if (attacker.get_hit_points() <= 0)
		std::cout << RED <<"ClapTrap " << attacker.getName() << " can't attack because it is dead" << std::endl << RESET;
	else if (attacker.get_energy_points() <= 0)
		std::cout << PURPLE <<"ClapTrap " << attacker.getName() << " has no energy" << std::endl << RESET;
}

void ClapTrap::get_damage(unsigned int amount)
{
	attack_damage = amount;
}
void ClapTrap::attack(const std::string& target)
{
	
	if (energy_points > 0 && hit_points > 0)
	{
		energy_points -=1;
		std::cout << GREEN << "ClapTrap " << name << " atacks " << target;
		std::cout << ",causing " << attack_damage << " points of damage!" << std::endl << RESET;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hit_points -= amount;
	if (hit_points <= 0)
		std::cout << RED << "ClapTrap " << name << " is dead" << std::endl << RESET;
	else
		std::cout << YELLOW << "ClapTrap " << name << " takes " << amount << " points of damage" << std::endl << RESET;
}