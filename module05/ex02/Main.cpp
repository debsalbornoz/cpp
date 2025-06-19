/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:51:49 by debs              #+#    #+#             */
/*   Updated: 2025/05/05 09:12:09 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int main(void)
{
    std::string name = "Debora";
    int grade = 75;
        Bureaucrat b(name, grade);
        Form f1 = Form("ShrubberyCreationForm", 145, 137);
        Form f2 = Form("RobotomyRequestForm", 72, 45);
        Form f3 = Form("PresidentialPardonForm", 25, 5);

        std::cout << MAGENTA <<"\nBureaucrat informatiom: " << std::endl << RESET;
        std::cout << MAGENTA << b << std::endl;
        f1.beSigned(b);
        std::cout << f1 << std::endl;
        f2.beSigned(b);
        std::cout << f2 << std::endl;
        f3.beSigned(b);
        std::cout << f3 << std::endl;
        
    return (0);       
}