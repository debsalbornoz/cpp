#include "Phonebook.hpp"
#include "Contact.hpp"

void PhoneBook::search_contact()
{
	int j = 1;
	std::string contact = "";
	std::cout << "index  | first name | last name  | nickname    | phone number | darkest secret " << "\n";
	for (int i = 0; i < len; i++)
	{
		std::cout << "   " << j << "   | " << my_contacts[i].get_name() << " | " << my_contacts[i].get_last_name();
		std::cout << " | " << my_contacts[i].get_nickname() << " | " << my_contacts[i].get_phone();
		std::cout << " | " << my_contacts[i].get_secret() << "\n";
		j++;
	}

}

int is_number(std::string str)
{
	int i = 0;
	while(str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void PhoneBook::select_contact()
{
	std::string index = "";
	int		value;
	std::cout << "Welcome to the contact viewer! \n Please enter the index of the contact you want to view: ";
	std::getline(std::cin, index);
	while (!is_number(index))
	{
		std::cout << "Invalid input! Please enter the index of the contact you want to view (or type 'EXIT' to return to the menu): ";
		std::getline(std::cin, index);
		if (index == "EXIT")
			return;
	}
	for (int i = 0; i < len; i++)
	{
		value = std::atoi(index.c_str()); 
		if (value == (i + 1))
			my_contacts[i].display_contact();
	}
}