#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy.name)
{
    *this = copy;
    std::cout << "ScavTrap " << name << " copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    if (this != &copy)
    {
        this->name = copy.name;
        this->hit_points = copy.hit_points;
        this->energy_points = copy.energy_points;
        this->attack_damage = copy.attack_damage;
    }
    std::cout << "ScavTrap " << name << " assignment operator called" << std::endl;
    return *this;
}


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
