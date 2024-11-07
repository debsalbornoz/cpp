#include "Phonebook.hpp"
#include "Contact.hpp"

int main(void)
{
    Phonebook my_phonebook;


    my_phonebook.my_contacts[my_phonebook.counter] = my_phonebook.my_contacts.save_contact();
    my_phonebook.counter++;
    my_phonebook.my_contacts.display_contact();
   return(0);
}