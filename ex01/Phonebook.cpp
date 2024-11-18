#include "Phonebook.hpp"
#include "Contact.hpp"

void PhoneBook::add_contact()
{
	if (counter >= 8)
		counter = 0;
	else
	{
		my_contacts[counter].save_contact();
		counter++;
	}
}

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
std::string number_to_string(int number)
{
	std::string result = "";
	bool negative = false;
	
	if (number == 0)
		return "0";
	if (number < 0)
	{
		negative = true;
		number = -number;
	}
	while (number > 0)
	{
		result = char('0' + (number % 10)) + result;
		number /= 10;
	}
	if (negative)
	{
		result = "-" + result;
	}
	return (result);
}

void PhoneBook::select_contact()
{
	std::string index = "";
	std::string idx = "";

	std::cout << "Select the contact index to display their information: ";
	std::getline(std::cin, index);
	while (!is_number(index))
		std::cout << "Select the contact index to display their information: ";
	for (int i = 0; i < len; i++)
	{
		idx = number_to_string(i);
		if (index == idx)
			my_contacts[i].display_contact();
	}
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
