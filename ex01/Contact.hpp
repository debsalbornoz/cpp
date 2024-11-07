
#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
    private:
        std::string name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        Contact save_contact();
        void display_contact();
};

#endif