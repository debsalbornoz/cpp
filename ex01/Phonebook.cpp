#include "Phonebook.hpp"
#include "Contact.hpp"

void Phonebook::add_contact()
{
    if (counter < 8)
    {
        my_contacts[counter].save_contact();
        counter++;
    }
}

void Phonebook::display_contacts()
{
    for (int i = 0; i < counter; i++)
    {
            std::cout << "Contact " << (i + 1) << ":\n";
        my_contacts[i].display_contact();
        std::cout << "----------------------\n";
    }
}

int main(void)
{
    Phonebook       my_phonebook;
    std::string     action = "";

    while(1)
    {
        std::cout << "SELECT: ADD, SEARCH, EXIT" << "\n";
        std::getline(std::cin, action);
        if (action == "ADD")
            my_phonebook.add_contact();
        else if (action == "EXIT")
            break;
    }
    my_phonebook.display_contacts();
   return(0);
}