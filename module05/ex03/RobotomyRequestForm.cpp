/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:58:19 by debs              #+#    #+#             */
/*   Updated: 2025/08/10 17:49:37 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45) , target("default") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) , target(target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src) {
    *this = src;
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;  
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
    AForm::operator=(rhs);
    this->target = rhs.target;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
        if (!this->getSignedStatus()|| executor.getGrade() > this->getExecGrade())
            throw AForm::GradeTooLowException();
        std::cout << "BZZZZZZZZZZZZZ (drilling noises)" << std::endl;
        if (rand() % 2) {
            std::cout << target << " has been robotomized successfully." << std::endl;
        } else {
            std::cout << "Robotomy failed on " << target << std::endl;
        }
}

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & rhs)
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