#include "Zombie.hpp"

int main(void)
{
    Horde my_horde;
    Zombie* my_zombie = my_horde.zombieHorde(5, "Zombie");

    for (int i = 0; i < 5; i++)
    {
        my_zombie[i].announce();
    }
    return 0;
}
