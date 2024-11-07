#include "Phonebook.hpp"
#include "Contact.hpp"

void PhoneBook::add_contact()
{
    if (counter >= 8)
        counter = 0;
    else
    {
        my_contacts[counter].save_contact();
        counter++;
    }
}

void PhoneBook::search_contact()
{
    std::cout << "index | first name | last name | nickname" << "\n"; 
    for (int i = 0; i < 8; i++)
    {
        std::cout << my_contacts[i].index << "\n";
    }
}

void PhoneBook::display_contacts()
{
    for (int i = 0; i < 8; i++)
    {
        std::cout << "Contact " << (i + 1) << ":\n";
        my_contacts[i].display_contact();
        std::cout << "----------------------\n";
    }
}

int main(void)
{
    PhoneBook       my_phonebook;
    std::string     action = "";

    while(1)
    {
        std::cout << "SELECT: ADD, SEARCH, EXIT" << "\n";
        std::getline(std::cin, action);
        if (action == "ADD")
            my_phonebook.add_contact();
        else if (action == "SEARCH")
            my_phonebook.search_contact();
        else if (action == "EXIT")
            break;
    }
    my_phonebook.display_contacts();
   return(0);
}
