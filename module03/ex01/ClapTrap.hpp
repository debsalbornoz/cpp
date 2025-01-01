#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <sstream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define PURPLE "\033[34m"
#define RESET "\033[0m"
#define PINK "\033[95m"
#define YELLOW "\033[33m"

class ClapTrap
{
    protected:
        std::string name;
        int hit_points;
        int energy_points;
        int attack_damage;
    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap &operator=(const ClapTrap &copy);
        ~ClapTrap();
        void attack(const std::string& target);
        void get_attack_damage(unsigned int attack_damage);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getName();
        int get_energy_points();
        int get_hit_points();
        int get_damage();
        
};

void initialize_claptraps_names(std::string &p1, std::string &p2);
void battle(ClapTrap &a, ClapTrap &b);
void status(ClapTrap &a, ClapTrap &b);
void repair(ClapTrap &a, ClapTrap &b);

#endif