/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:51:49 by debs              #+#    #+#             */
/*   Updated: 2025/07/27 20:50:35 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int main(void)
{
    std::string name = "Debora";
    int grade = 75;
        Bureaucrat b(name, grade);
        Form f1 = Form("Shrubbery Creation", 145, 137);
        Form f2 = Form("Robotomy Request", 72, 45);
        Form f3 = Form("Presidential Pardon", 25, 5);

        std::cout << b << std::endl;
        std::cout << f1;
        b.signForm(f1);
        std::cout << std::endl;
        std::cout << f2;
        b.signForm(f2);
        std::cout << std::endl;
        std::cout << f3;
        b.signForm(f3);
        std::cout << std::endl;
    return (0);       
}