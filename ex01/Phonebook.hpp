
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"
#include <cstdlib>
#include <cwchar>
#include <iomanip>

class	PhoneBook
{
	public:
		Contact	my_contacts[8];
		int	counter;
		int len;
	public:
		PhoneBook() : counter(0) {}
		void add_contact();
		void display_contacts();
		void search_contact();
		void select_contact();
		void print_contact(std::string str);
};

#endif