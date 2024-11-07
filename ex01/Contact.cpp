#include "Phonebook.hpp"
#include "Contact.hpp"

Contact Contact::save_contact(void)
{
    std::cout << "Name : \n";
    std::getline(std::cin, name);
    std::cout << "Last name : \n";
    std::getline(std::cin, last_name);
    std::cout << "Nickname : \n";
    std::getline(std::cin, nickname);
    std::cout << "Phone number : \n";
    std::getline(std::cin, phone_number);
    std::cout << "Darkest secret : \n";
    std::getline(std::cin, darkest_secret);
    return *this;
}

void Contact::display_contact()
{
    std::cout << name << "\n";
    std::cout << last_name << "\n";
    std::cout << nickname << "\n";
    std::cout << phone_number << "\n";
    std::cout << darkest_secret << "\n";
}