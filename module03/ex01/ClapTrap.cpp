#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy): name(copy.name), hit_points(copy.hit_points), energy_points(copy.energy_points), attack_damage(copy.attack_damage)
{
    std::cout << "ClapTrap " << name << "copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    if (this != &copy)
    {
        name = copy.name;
        hit_points = copy.hit_points;
        energy_points = copy.energy_points;
        attack_damage = copy.attack_damage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destructor called" << std::endl;
}

void initialize_claptraps_names(std::string &p1, std::string &p2)
{
    std::cout << "Enter name of first Claptrap: \n";
    std::getline(std::cin, p1);

    std::cout << "Enter name of second Claptrap: \n";
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
int ClapTrap::get_damage()
{
    return (attack_damage);
}
void status(ClapTrap &a, ClapTrap &b)
{
    std::cout << PURPLE << a.getName() << " has " << a.get_hit_points() << " hit points and " << a.get_energy_points() << " energy points\n";
    std::cout << b.getName() << " has " << b.get_hit_points() << " hit points and " << b.get_energy_points() << " energy points\n" << RESET;
}


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
}

void repair(ClapTrap &a, ClapTrap &b)
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
    if (energy_points > 0)
    {
        hit_points += amount;
        energy_points -= 1;
    }
}


