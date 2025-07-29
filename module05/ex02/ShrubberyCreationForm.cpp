/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:58:19 by debs              #+#    #+#             */
/*   Updated: 2025/07/28 13:22:26 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137) {
    this->setTarget("default");
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) 
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
    this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
    AForm::operator=(rhs);
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
        if (!this->getSignedStatus())
            throw AForm::FormNotSignedException();
        if (executor.getGrade() > this->getExecGrade())
            throw AForm::GradeTooLowException();
        createShrubbery();
}

void ShrubberyCreationForm::createShrubbery()
{
    std::ofstream file(this->getTarget() + "_shrubbery");
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file");
    }

    file << "        *\n";
    file << "       /_\\\n";
    file << "      /___\\\n";
    file << "     /_____\\\n";
    file << "    /_______\\\n";
    file << "   /_________\\\n";
    file << "  /___________\\\n";
    file << "       |||\n";
    file << "       |||\n";
    file << "  ****************\n";

    file.close();
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & rhs)
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