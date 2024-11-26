#include "Phonebook.hpp"
#include "Contact.hpp"

void PhoneBook::add_contact()
{
	if (counter > 7)
		counter = 0;
	my_contacts[counter].save_contact();
	counter++;
}

void Contact::save_contact(void)
{
	name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";

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
