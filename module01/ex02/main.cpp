#include <iostream>

int main(void)
{
	std::string str="HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Memory address of the string variable: " << &str << "\n";
	std::cout << "Memory address held by stringPTR: " << stringPTR << "\n";
	std::cout << "Memory adress held by stringREF: " << &stringREF << "\n";

	std::cout << "The value of the string variable: " << str << "\n";
	std::cout << "The value pointed by stringPTR: " << *stringPTR << "\n";
	std::cout << "The value pointed by stringREF: " << stringREF << "\n";
}