/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:29:03 by debs              #+#    #+#             */
/*   Updated: 2025/05/05 09:06:32 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("random name"), signedStatus(false), signGrade(150), execGrade(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade)
{
    this->signedStatus = false;
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form constructor called" << std::endl;
}

Form::~Form(void)
{
    std::cout << "Form destructor called" << std::endl;
}   

Form::Form(const Form &copy) : name(copy.name), signedStatus(copy.signedStatus), signGrade(copy.signGrade), execGrade(copy.execGrade)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &copy)
{
    if (this != &copy)
    {
        this->signedStatus = copy.signedStatus;
    }
    std::cout << "Form assignment operator called" << std::endl;
    return *this;
}

std::string Form::getName() const
{
    return (this->name);
}

int Form::getSignGrade() const
{
    return (this->signGrade);
}

int Form::getExecGrade() const
{
    return (this->execGrade);
}

bool Form::getSignedStatus() const
{
    return (this->signedStatus);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    try
    {
        if (!bureaucrat.signForm(*this))
            throw Form::GradeTooLowException();
        this->signedStatus = true;
    } catch (const std::exception &e) {
        std::cout << RED << e.what() << std::endl << RESET;
        return;
    }
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << PURPLE << "Name: " << RESET;
    out << form.getName() << std::endl;
    out << PURPLE << "Signed: "  << RESET;
    out << form.getSignedStatus() << std::endl;
    out << PURPLE << "Sign grade required: " << RESET;
    out << form.getSignGrade() << std::endl;   
    out << PURPLE <<"Exec grade required: " << RESET;
    out << form.getExecGrade() << std::endl;
    return (out);
}
