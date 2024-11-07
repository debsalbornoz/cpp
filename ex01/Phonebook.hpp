
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class   Phonebook
{
    public:
        Contact my_contacts[8];
        int     counter;
    public:
        Phonebook() : counter(0) {}
        void add_contact();
        void display_contacts();
};

#endif