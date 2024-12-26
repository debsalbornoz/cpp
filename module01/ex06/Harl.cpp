#include "Harl.hpp"

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << BLUE;
	std::cout << "Debug : I love having extra bacon for my";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger.\n I really do!\n";
}
void Harl::info( void )
{
	std::cout << GREEN;
	std::cout << "Info: I cannot believe adding extra bacon costs more money.";
	std::cout << "You didn’t put enough bacon in my burger!\n If you did, I wouldn’t be asking for more!\n";
	std::cout << END;
}
void Harl::warning( void )
{
	std::cout << YELLOW;
	std::cout << "Warning: I think I deserve to have some extra bacon for free.";
	std::cout << "I’ve been coming for years whereas you\n started working here since last month.\n";
	std::cout << END;
}
void Harl::error( void )
{
	std::cout << RED;
	std::cout << "Error: This is unacceptable! I want to speak to the manager now.\n";
	std::cout << END;
}

void Harl::complain( std::string level )
{
	int i = -1;
	std::string complains[4] = {
		"DEBUG",
		"INFO", 
		"WARNING",
		"ERROR" 
	};

	for (int j = 0; j < 4; j++)
	{
		if (complains[j] == level)
		{
			i = j;
			break;
		}
	}
	switch(i)
	{
		case 0:
		{
			debug();
			info();
			warning();
			error();
			break;
		}
		case 1:
		{
			info();
			warning();
			error();
			break;
		case 2:
		{
			warning();
			error();
			break;
		}
		case 3:
			error();
			break;
		default:
		{
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
		}
	}
}
}
