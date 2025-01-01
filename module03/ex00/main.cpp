#include "ClapTrap.hpp"

int main(void)
{
    std::string p1 = "";
    std::string p2 = "";
    std::string action = "";

    initialize_claptraps_names(p1, p2);
    ClapTrap a(p1);
    ClapTrap b(p2);

    while (action != "EXIT" && (a.get_hit_points() > 0) && (b.get_hit_points() > 0))
    {
        std::cout << "Select: ATTACK, REPAIR, STATUS or EXIT\n";
        std::getline(std::cin, action);
        if (action == "ATTACK")
           battle(a, b);
        else if (action == "REPAIR")
            repair(a, b);
        else if (action == "STATUS")
            status(a, b);
        else if (action != "EXIT")
            std::cout << RED << "Invalid action. Please enter a valid action.\n" << RESET;
    }

    return (0);
}
