
#include <iostream>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        Contact();
        void    create_contact();
        void    get_first_name();
        void    get_last_name();
        void    get_nickname();
        void    get_phone_nbr();
        void    get_darkest_secret();        
        void    display();
};

