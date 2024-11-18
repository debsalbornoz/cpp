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
	std::cout << "Name: " << name << "\n";
	std::cout << "Last name:" << last_name << "\n";
	std::cout << "Nickname: " << nickname << "\n";
	std::cout << "Phone number: " << phone_number << "\n";
	std::cout << "Darkest secret:" << darkest_secret << "\n";
}

std::string Contact::get_name()
{
	std::string new_str;

	new_str = name;
	if (name.size() > 10)
	{
		new_str = name.substr(0, 9);
		new_str += ".";
	}
	return (new_str);
}

std::string Contact::get_last_name()
{
	std::string new_str;

	new_str = last_name;
	if (name.size() > 10)
	{
		new_str = last_name.substr(0, 9);
		new_str += ".";
	}
	return (new_str);
}

std::string Contact::get_nickname()
{
	std::string new_str;

	new_str = nickname;
	if (nickname.size() > 10)
	{
		new_str = nickname.substr(0, 9);
		new_str += ".";
	}
	return (new_str);
}

std::string Contact::get_phone()
{
	std::string new_str;

	new_str = phone_number;
	if (phone_number.size() > 10)
	{
		new_str = phone_number.substr(0, 9);
		new_str += ".";
	}
	return (new_str);
}

std::string Contact::get_secret()
{
	std::string new_str;

	new_str = darkest_secret;
	if (darkest_secret.size() > 10)
	{
		new_str = darkest_secret.substr(0, 9);
		new_str += ".";
	}
	return (new_str);
}

