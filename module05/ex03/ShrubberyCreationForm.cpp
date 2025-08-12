/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:58:19 by debs              #+#    #+#             */
/*   Updated: 2025/08/11 17:45:46 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), target("default") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) , target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src) {
    *this = src;
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;  
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
    AForm::operator=(rhs);
    this->target = rhs.target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
        if (!this->getSignedStatus())
            throw AForm::FormNotSignedException();
        if (executor.getGrade() > this->getExecGrade())
            throw AForm::GradeTooLowException();
        createShrubbery();
}

void ShrubberyCreationForm::createShrubbery() const {
    std::ofstream file((this->target + "_shrubbery").c_str());
    if (!file) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return;
    }
    file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "       | |\n";

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