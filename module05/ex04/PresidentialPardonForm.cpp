/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:58:19 by debs              #+#    #+#             */
/*   Updated: 2025/08/11 17:47:25 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 72, 45) , target("default") {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 72, 45) , target(target)
{
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src) {
    *this = src;
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;  
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
    AForm::operator=(rhs);
    this->target = rhs.target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!this->getSignedStatus())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & rhs)
{
    o << PURPLE << "Name: " << RESET;
    o << rhs.getName() << std::endl;
    o << PURPLE << "Signed: "  << RESET;
    o << rhs.getSignedStatus() << std::endl;
    o << PURPLE << "Sign grade required: " << RESET;
    o << rhs.getSignGrade() << std::endl;   
    o << PURPLE <<"Exec grade required: " << RESET;
    o << rhs.getExecGrade() << std::endl;
    return (o);
}