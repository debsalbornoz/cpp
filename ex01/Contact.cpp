#include "Phonebook.hpp"


bool is_not_digits(std::string phone_nbr)
{
    for (size_t i = 0; i < phone_nbr.length(); i++)
        if (!std::isdigit(phone_nbr[i]))
            return (false);
    return (true);
}

void Contact::get_first_name()
{
    std::string name;

    while (true)
    {
        std::cout << "Enter your first name: ";
        std::getline(std::cin, name);

        size_t start = name.find_first_not_of(" \t");
        size_t end = name.find_last_not_of(" \t");

        if (start != std::string::npos && end != std::string::npos)
            name = name.substr(start, end - start + 1);
        else
            name.clear();
        if (!name.empty())
            break;
        else
            std::cout << "Please provide valid information, the first name can't be empty.\n";
    }
    first_name = name;
}

void Contact::get_last_name()
{
    std::string lastname = "";
    size_t start = 0;
    size_t end = 0;

    while(true)
    {
        std::cout << "Enter your last name: ";
        std::getline(std::cin, lastname);
        start = lastname.find_first_not_of(" \t");
        end = lastname.find_last_not_of(" \t");
        if (start != std::string::npos && end != std::string::npos)
            lastname = lastname.substr(start, end - start + 1);
        else
            lastname.clear();
        if (!lastname.empty())
            break;
        else
            std::cout << "Please provide valid information, the last name can't be empty.\n";
    }
    last_name = lastname;
}

void Contact::get_nickname()
{
    std::string Nickname = "";
    size_t start = 0;
    size_t end = 0;

    while(true)
    {
        std::cout << "Enter your nickname: ";
        std::getline(std::cin, Nickname);
        start = Nickname.find_first_not_of(" \t");
        end = Nickname.find_last_not_of(" \t");
        if (start != std::string::npos && end != std::string::npos)
            Nickname = Nickname.substr(start, end - start + 1);
        else
            Nickname.clear();
        if (!Nickname.empty())
            break;
        else
            std::cout << "Please provide valid information, the nickname name can't be empty.\n";
    }
    nickname = Nickname;
}

void Contact::get_phone_nbr()
{
    std::string phone_nbr = "";
    size_t start = 0;
    size_t end = 0;

    while(true)
    {
        std::cout << "Enter your phone number: ";
        std::getline(std::cin, phone_nbr);
        start = phone_nbr.find_first_not_of(" \t");
        end = phone_nbr.find_last_not_of(" \t");
        if (start != std::string::npos && end != std::string::npos)
            phone_nbr = phone_nbr.substr(start, end - start + 1);
        else
            phone_nbr.clear();
        if (!phone_nbr.empty())
        {
            if (!is_not_digits(phone_nbr))
                std::cout << "Please provide valid information, the phone number sould be only digits.\n";
            else
               break;
        }
        else
            std::cout << "Please provide valid information, the phone number name can't be empty.\n";
    }
    phone_number = phone_nbr;
}

void Contact::get_darkest_secret()
{
    std::string secret = "";
    size_t start = 0;
    size_t end = 0;

    while(true)
    {
        std::cout << "Enter your secret: ";
        std::getline(std::cin, secret);
        start = secret.find_first_not_of(" \t");
        end = secret.find_last_not_of(" \t");
        if (start != std::string::npos && end != std::string::npos)
            secret = secret.substr(start, end - start + 1);
        else
            secret.clear();
        if (!secret.empty())
            break;
        else
            std::cout << "Please provide valid information, the darkest secret can't be empty.\n";
    }
    darkest_secret = secret;
}
