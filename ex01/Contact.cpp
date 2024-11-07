#include "Phonebook.hpp"
#include "Contact.hpp"

void Contact::save_contact(void)
{
    while (name == "")
    {
        std::cout << "Name : \n";
        std::getline(std::cin, name);
    }
    while(last_name == "")
    {
        std::cout << "Last name : \n";
        std::getline(std::cin, last_name);
    }
    while(nickname == "")
    {
        std::cout << "Nickname : \n";
        std::getline(std::cin, nickname);
    }
    while (phone_number == "")
    {
        std::cout << "Phone number : \n";
        std::getline(std::cin, phone_number);
    }
    while(darkest_secret == "")
    {
        std::cout << "Darkest secret : \n";
        std::getline(std::cin, darkest_secret);
    }
    index++;
}

void Contact::display_contact()
{
    std::cout << name << "\n";
    std::cout << last_name << "\n";
    std::cout << nickname << "\n";
    std::cout << phone_number << "\n";
    std::cout << darkest_secret << "\n";
    //std::cout << index << "\n";
}