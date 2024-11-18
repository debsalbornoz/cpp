
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

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
};

#endif