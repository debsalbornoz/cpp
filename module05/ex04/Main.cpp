/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:50:44 by debs              #+#    #+#             */
/*   Updated: 2025/08/12 09:07:15 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
    Intern  someRandomIntern;

    std::cout << "\n---- Creating Forms ----" << std::endl;
    AForm *f1= someRandomIntern.makeForm("shrubbery creation", "garden");
    AForm *f2= someRandomIntern.makeForm("robotomy request", "Bender");
    AForm *f3= someRandomIntern.makeForm("presidential pardon", "Fry");
    AForm *f4= someRandomIntern.makeForm("time travel request", "Delorean");
    
    std::cout << "\n----Printing Forms ----" << std::endl;
    if (f1)
        std::cout << *f1<< std::endl;
    if (f2)
        std::cout << *f2<< std::endl;
    if(f3)
        std::cout << *f3<< std::endl;
    if(f4)
        std::cout << *f4<< std::endl;

    std::cout << "\n---- Deleting forms ----" << std::endl;
    someRandomIntern.deleteForm(f1);
    someRandomIntern.deleteForm(f2);
    someRandomIntern.deleteForm(f3);
    someRandomIntern.deleteForm(f4);
    return (0);
    }

