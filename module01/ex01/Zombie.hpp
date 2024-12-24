#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string name;
        int index;
    public:
        Zombie();
        ~Zombie();
        void announce(void);
        void setName(std::string zombie_name);
        void setIndex(int i);
};

class Horde
{
    private:
        Zombie *zombies;
    public:
        Horde();
        ~Horde();
        Zombie* zombieHorde( int N, std::string name );
};

#endif