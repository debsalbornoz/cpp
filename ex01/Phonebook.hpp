
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
        Phonebook   add_contact();
};

#endif