/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:50:44 by debs              #+#    #+#             */
/*   Updated: 2025/08/11 09:51:27 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
    Intern  someRandomIntern;
    AForm*  form;

    std::cout << "\n---- Testing valid forms ----" << std::endl;

    form = someRandomIntern.makeForm("shrubbery creation", "garden");
    if (form) {
        std::cout << *form << std::endl;
        someRandomIntern.deleteForm(form);
    }

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << *form << std::endl;
        someRandomIntern.deleteForm(form);
    }

    form = someRandomIntern.makeForm("presidential pardon", "Fry");
    if (form) {
        std::cout << *form << std::endl;
        someRandomIntern.deleteForm(form);
    }

    std::cout << "\n---- Testing invalid form ----" << std::endl;

    form = someRandomIntern.makeForm("time travel request", "Delorean");
    if (form) {
        std::cout << *form << std::endl;
        someRandomIntern.deleteForm(form);
    }

    return 0;
}
