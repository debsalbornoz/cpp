#include "Zombie.hpp"

int main(void)
{
	Horde	my_horde;
	int		size = 10;

	Zombie* my_zombie = my_horde.zombieHorde(size, "Zombie");

	for (int i = 0; i < size; i++)
	{
		my_zombie[i].announce();
	}
	return (0);
}
