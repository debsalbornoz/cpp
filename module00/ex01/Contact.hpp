
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		int index;
		std::string get_name();
		std::string get_last_name();
		std::string get_nickname();
		std::string get_phone();
		std::string get_secret();
		void save_contact();
		void display_contact();
		void initialize_contact();
};

#endif