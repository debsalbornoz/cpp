#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 30;
    std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destructor called" << std::endl;
}
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy.name)
{
    *this = copy;
    std::cout << "FragTrap " << name << " copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    if (this != &copy)
    {
        this->name = copy.name;
        this->hit_points = copy.hit_points;
        this->energy_points = copy.energy_points;
        this->attack_damage = copy.attack_damage;
    }
    std::cout << "FragTrap " << name << " assignment operator called" << std::endl;
    return *this;
}


void FragTrap::attack(const std::string& target)
{
    energy_points -= 1;
    std::cout << GREEN << "FragTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl << RESET;
}

void battle(FragTrap &a, FragTrap &b)
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
            a.FragBattle(b,a);
        else if (target == b.getName() && a.get_hit_points() > 0 )
            b.FragBattle(a,b);
    }
}

void FragTrap::FragBattle(FragTrap &attacker, FragTrap &target)
{
    if (attacker.get_energy_points() <= 0)
    {
        std::cout << RED << "FragTrap " << attacker.getName() << " has no energy" << std::endl << RESET;
        return;
    }
    else
        attacker.attack(target.getName());
    if (target.get_hit_points() <= 0)
        std::cout << RED << "FragTrap " << name << " is dead" << std::endl << RESET;
    else
    {
        target.takeDamage(attacker.get_damage());
        if (target.get_hit_points() <= 0)
            std::cout << RED << "FragTrap " << name << " is dead" << std::endl << RESET;
        else
            std::cout << YELLOW << "FragTrap " << name << " takes " << attacker.get_damage() << " points of damage" << std::endl << RESET;
    }
}

void repair(FragTrap &a, FragTrap &b)
{
    std::string amount = "";
    std::string FragTrap = "";

    while (FragTrap != a.getName() && FragTrap != b.getName())
    {
        std::cout << "Enter FragTrap to be repaired: \n";
        std::getline(std::cin, FragTrap);

        if (FragTrap != a.getName() && FragTrap != b.getName()) 
        {
            std::cout << "Invalid target. Please enter a valid name.\n";
            continue;
        }
        std::cout << "Enter amount to be repaired: \n";
        std::getline(std::cin, amount);

        unsigned int amount_repaired = 0;
        std::istringstream(amount) >> amount_repaired;

        if (FragTrap == a.getName())
            a.FragRepair(a, amount_repaired);
        else if (FragTrap == b.getName())
           b.FragRepair(b, amount_repaired);
    }
}

void FragTrap::FragRepair(FragTrap &a, int amount_repaired)
{
    if (a.get_energy_points()>= 0 && a.get_hit_points() > 0)
    {
        a.beRepaired(amount_repaired);
        std::cout << PINK << "FragTrap " << a.getName() << " is repaired for " << amount_repaired << " hit points" << std::endl << RESET;
    }
    if (a.get_energy_points() <= 0)
        std::cout << PINK << "FragTrap " << a.getName() << " has no energy" << std::endl << RESET;
    if (a.get_hit_points() <= 0)
        std::cout << RED << "FragTrap " << a.getName() << " is dead" << std::endl << RESET;
}

void	FragTrap::highFivesGuys(void) 
{
	std::cout << PURPLE << "FragTrap " << this->name << " high fives guys!" << std::endl << RESET;
	energy_points -= 1;
}

void initialize_names(std::string &p1, std::string &p2)
{
    std::cout << "Enter first: \n";
    std::getline(std::cin, p1);

    std::cout << "Enter second name: \n";
    std::getline(std::cin, p2);
}

void status(FragTrap &a, FragTrap &b)
{
    std::cout << PURPLE << a.getName() << " has " << a.get_hit_points() << " hit points and " << a.get_energy_points() << " energy points\n";
    std::cout << b.getName() << " has " << b.get_hit_points() << " hit points and " << b.get_energy_points() << " energy points\n" << RESET;
}