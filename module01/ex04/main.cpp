#include "ft_sed.hpp"


int main(int argc, char **argv)
{
    if (argc == 4)
    {
        std::ifstream file;
        std::ofstream file_replace;

        open_file(argv[1], file);
        create_new_file(argv[1], file_replace);
        duplicate_and_replace(file, file_replace, argv[2], argv[3]);
        file.close();
        file_replace.close();
    } else {
        std::cerr << "Error: wrong number of arguments" << std::endl;
    }
    return 0;
}
