#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::string a = "";
    std::string b = "";
    std::string action = "";

    initialize_scavtrap_names(a, b);

    ScavTrap Scav(a);
    ScavTrap Trap(b);

    while (action != "5" && (Scav.get_hit_points() > 0) && (Trap.get_hit_points() > 0))
    {
        std::cout << "Select: 1.ATTACK, 2.REPAIR, 3.STATUS, 4.GUARD GATE or 5.EXIT\n";
        std::getline(std::cin, action);
        if (action == "1")
           battle(Scav, Trap);
        else if (action == "2")
            repair(Scav, Trap);
        else if (action == "3")
            status(Scav, Trap);
        else if (action == "4")
            Scav.guardGate();
        else if (action != "5")
            std::cout << RED << "Invalid action. Please enter a valid action.\n" << RESET;
    }

    return (0);
}