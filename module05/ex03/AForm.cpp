/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:29:03 by debs              #+#    #+#             */
/*   Updated: 2025/08/10 17:00:52 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("default"), signedStatus(false), signGrade(150), execGrade(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade)
{
    this->signedStatus = false;
    try
    {
        checkGrade(signGrade, execGrade);
    }
    catch (const std::exception &e) {
        std::cout << RED << e.what() << std::endl << RESET;
        return;
    }
    std::cout << "AForm " << this->name << " constructor called" << std::endl;
}

void AForm::checkGrade(int signGrade, int execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();    
}
AForm::~AForm(void)
{
    std::cout << "AForm " << this->name << " destructor called" << std::endl;
}   

AForm::AForm(const AForm &copy) : name(copy.name), signedStatus(copy.signedStatus), signGrade(copy.signGrade), execGrade(copy.execGrade)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
    if (this != &copy)
    {
        this->signedStatus = copy.signedStatus;
    }
    std::cout << "AForm assignment operator called" << std::endl;
    return *this;
}

std::string AForm::getName() const
{
    return (this->name);
}

int AForm::getSignGrade() const
{
    return (this->signGrade);
}

int AForm::getExecGrade() const
{
    return (this->execGrade);
}

bool AForm::getSignedStatus() const
{
    return (this->signedStatus);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
       if (bureaucrat.getGrade() > this->signGrade)
            throw AForm::GradeTooLowException();
        this->signedStatus = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
    out << PURPLE << "Name: " << RESET;
    out << AForm.getName() << std::endl;
    out << PURPLE << "Signed: "  << RESET;
    out << AForm.getSignedStatus() << std::endl;
    out << PURPLE << "Sign grade required: " << RESET;
    out << AForm.getSignGrade() << std::endl;   
    out << PURPLE <<"Exec grade required: " << RESET;
    out << AForm.getExecGrade() << std::endl;
    return (out);
}
