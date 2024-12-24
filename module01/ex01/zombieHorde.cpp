#include "Zombie.hpp"

Horde::Horde() : zombies(NULL) {}

Horde::~Horde(){
    delete[] zombies;
}
Zombie* Horde::zombieHorde( int N, std::string name )
{
    zombies = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombies[i].setName(name);
        zombies[i].setIndex(i);
    }
    return (zombies);
}

void free_zombies(int i, Zombie *zombies)
{
    (void)i;
    delete [] zombies;
}