#include "Phonebook.hpp"

/*void    Contact::add_contact_info(std::string name, std::string surname, std::string nickname, std::string number, std::string secret)
{
    return (0);
}
*/


void    Contact::display()
{
    std::cout << first_name << "\n";
    std::cout << last_name << "\n";
    std::cout << nickname << "\n";
    std::cout << phone_number << "\n";
}

int main(void)
{
    Contact     contact;
    std::string    action = "";

    std::cout << "Welcome to my phonebook!\n";
    while (1)
    {   
        std::cout << "Select : ADD, SEARCH, EXIT\n";
        std::cin >> action;
        if (action == "ADD")
        {
            contact.create_contact();
            contact.display();
        }
        else if (action == "SEARCH")
            std::cout << "teste";
        else if (action == "EXIT")
            break;
        else
            std::cout << "Please select: ADD, SEARCH OR EXIT\n";
    }
    return (0);
}