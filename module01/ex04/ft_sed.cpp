#include "ft_sed.hpp" // Para usar exit()

void open_file(const std::string &filename, std::ifstream &file)
{
    file.open(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: file not found\n";
        exit(1);
    }
}

void create_new_file(const std::string &filename, std::ofstream &file_replace)
{
    file_replace.open((filename + ".replace").c_str());
    if (!file_replace.is_open()) {
        std::cerr << "Error: file not found\n";
        exit(1);
    }
}