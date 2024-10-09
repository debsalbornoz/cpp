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
    Contact contact;

    contact.get_first_name();
    contact.get_last_name();
    contact.get_nickname();
    contact.get_phone_nbr();
    contact.get_darkest_secret();
    contact.display();
    return (0);
}