/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:16:18 by debs              #+#    #+#             */
/*   Updated: 2025/08/12 09:11:58 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void){
    std::cout << "Intern default constructor called" << std::endl;
}


Intern::Intern(Intern const & src){
    *this = src;
    std::cout << "Intern copy constructor called" << std::endl;  
}

Intern::~Intern(void) {
    std::cout << "Intern destructor called" << std::endl;
}

Intern & Intern::operator=(Intern const & rhs) {
    (void)rhs;
    return *this;
}

AForm* Intern::makePardonForm(std::string target) {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeRobotomyForm(std::string target) {
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makeShrubberyForm(std::string target) {
    return (new ShrubberyCreationForm(target));
}

typedef AForm* (*FormCreator)(std::string); // agora ponteiro para função normal

AForm* Intern::makeForm(std::string name, std::string target) {
    std::string names[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    FormCreator creators[3] = {
        &Intern::makeRobotomyForm,
        &Intern::makePardonForm,
        &Intern::makeShrubberyForm
    };

    for (int i = 0; i < 3; ++i) {
        if (names[i] == name) {
            std::cout << "Intern creates " << name << std::endl;
            return creators[i](target); // não precisa mais de `this`
        }
    }

    std::cout << "Intern could not find the form: " << name << std::endl;
    return NULL;
}

void Intern::deleteForm(AForm *&form) {
    if (form == NULL)
        return;
    delete form;
    form = NULL;
}