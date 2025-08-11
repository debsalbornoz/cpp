/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:51:49 by debs              #+#    #+#             */
/*   Updated: 2025/08/11 17:43:44 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    
    std::cout << "\n---- Creating Bureaucrats ----" << std::endl;
    Bureaucrat lowRank("Bob", 150);
    Bureaucrat midRank("Alice", 50);
    Bureaucrat highRank("Zaphod", 1);

    std::cout << "\n---- Creating Forms ----" << std::endl;
    ShrubberyCreationForm shrubForm("garden");
    RobotomyRequestForm robotForm("Marvin");
    PresidentialPardonForm pardonForm("Ford");

    std::cout << "\n---- Trying to Execute Unsigned Forms ----" << std::endl;
    lowRank.executeForm(shrubForm);
    midRank.executeForm(shrubForm);
    highRank.executeForm(shrubForm);

    std::cout << "\n---- Signing Forms ----" << std::endl;
    lowRank.signForm(shrubForm);
    midRank.signForm(shrubForm);
    midRank.signForm(robotForm);
    highRank.signForm(pardonForm);
    highRank.signForm(robotForm);
        
    std::cout << "\n---- Executing Forms ----" << std::endl;
    lowRank.executeForm(shrubForm);
    midRank.executeForm(shrubForm);
    highRank.executeForm(shrubForm);
    
    std::cout << "\n---- Executing Robotomy Multiple Times ----" << std::endl;
    for (int i = 0; i < 4; ++i) {
        highRank.executeForm(robotForm);
    }

    std::cout << "\n---- Executing Presidential Pardon ----" << std::endl;
    highRank.executeForm(pardonForm);
    std::cout << std::endl;
    return 0;
}
