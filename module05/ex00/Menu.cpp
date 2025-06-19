/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:31:31 by dlamark-          #+#    #+#             */
/*   Updated: 2025/06/19 17:36:32 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Menu.hpp"

bool Menu::isNumber(std::string str)
{
	if (str.empty())
		return (false);
	int i = 0;
	if (str[i] == '-')
		i = 1;
	for (size_t j = i;  j < str.length(); j++)
	{
		if (!isdigit(str[j]))
			return (false);
	}
	return (true);
}

int Menu::insertGrade()
{
	std::string grade;
		
	while (1)
	{
		std::cout << PURPLE << "Insert grade:" << std::endl << RESET;
		std::getline(std::cin, grade);
		if (isNumber(grade))
		{
			return (atoi(grade.c_str()));
		}
		else
			std::cout << RED << "Invalid input" << std::endl << RESET;
	}
}

void Menu::displayMenu()
{
	std::cout << PURPLE << "Select action:" << std::endl;
	std::cout << "1 - Increment grade" << std::endl;
	std::cout << "2 - Decrement grade" << std::endl;
	std::cout << "3 - Set grade" << std::endl;
	std::cout << "4 - Display information" << std::endl;
	std::cout << "5 - Exit" << std::endl << RESET;
}

void Menu::runMenu(Bureaucrat &b)
{
	bool running = true;
	std::string action = "";
	while(running)
	{
		displayMenu();
		std::getline(std::cin, action);
		if (action == "1")
			b.incrementGrade();
		else if (action == "2")
			b.decrementGrade();
		else if (action == "3")
		{
			int grade = insertGrade();
			b.setGrade(grade);
		}
		else if (action == "4")
			std::cout << b << std::endl;
		else if (action == "5")
			running = false;
		else if (action != "5")
			std::cout << RED << "Invalid action. Please enter a valid action.\n" << RESET;
	}
}