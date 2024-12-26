#include "ft_sed.hpp" 

void open_file(const std::string &filename, std::ifstream &file)
{
	file.open(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error\n";
		exit(1);
	}
}

void create_new_file(const std::string &filename, std::ofstream &file_replace)
{
	file_replace.open((filename + ".replace").c_str());
	if (!file_replace.is_open()) {
		std::cerr << "Error\n";
		exit(1);
	}
}

void duplicate_and_replace(std::ifstream &file_in, std::ofstream &file_out, const std::string &s1, const std::string &s2)
{
	std::string linha;

	while (std::getline(file_in, linha))
	{
		size_t pos = 0;

		while ((pos = linha.find(s1, pos)) != std::string::npos)
		{
			linha.erase(pos, s1.length());
			linha.insert(pos, s2);
			pos += s2.length();
		}
		file_out << linha << "\n";
	}
}