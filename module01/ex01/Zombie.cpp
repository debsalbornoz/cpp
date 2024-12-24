#include "Zombie.hpp"

Zombie::Zombie() : name("") {}
Zombie::~Zombie()
{
    std::cout << name << " " <<index << " has been destroyed.\n";
}

void Zombie::announce(void)
{
    std::cout << name << " " << index << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string zombie_name)
{
    name = zombie_name;
}

void Zombie::setIndex(int i)
{
    index = i + 1;
}