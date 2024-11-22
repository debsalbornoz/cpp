#include "Phonebook.hpp"
#include "Contact.hpp"

int main(void)
{
	PhoneBook	my_phonebook;
	std::string	action = "";
	my_phonebook.len = 0;

	while(1)
	{
		std::cout << "SELECT: ADD, SEARCH, EXIT" << "\n";
		std::getline(std::cin, action);
		if (action == "ADD")
		{
			my_phonebook.add_contact();
			my_phonebook.len++;
		}
		else if (action == "SEARCH")
		{
			my_phonebook.search_contact();
			my_phonebook.select_contact();
		}
		else if (action == "EXIT")
			break;
	}
	my_phonebook.display_contacts();
	return(0);
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
