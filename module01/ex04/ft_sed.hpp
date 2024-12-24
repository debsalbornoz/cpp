#ifndef FT_SED_HPP
#define FT_SED_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

void open_file(const std::string &filename, std::ifstream &file);
void create_new_file(const std::string &filename, std::ofstream &file_replace);
void duplicate_and_replace(std::ifstream &file, std::ofstream &file_replace, const std::string &s1, const std::string &s2);
#endif
