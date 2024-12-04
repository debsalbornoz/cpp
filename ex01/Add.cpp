#include "Phonebook.hpp"
#include "Contact.hpp"

std::string get_input(std::string str)
{
	std::string input;

	while (input == "")
	{
		std::cout << str;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return(NULL);
	}
	return (input);
}

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

	name = get_input("Name : ");
	last_name = get_input("Last name : ");
	nickname = get_input("Nickname : ");
	phone_number = get_input("Phone_number : ");
	darkest_secret = get_input("Darkest secret : ");
	index++;
}
