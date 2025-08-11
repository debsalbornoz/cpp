/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:29:03 by debs              #+#    #+#             */
/*   Updated: 2025/08/11 16:51:54 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("default"), signedStatus(false), signGrade(150), execGrade(150)
{
    std::cout << GREEN << "Form default constructor called" << std::endl << RESET;
}

Form::Form(std::string name, int signGrade, int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade)
{
    this->signedStatus = false;
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();    
    std::cout << GREEN  << "Form " << this->name << " constructor called" << std::endl << RESET;
}

Form::~Form(void)
{
    std::cout << RED << "Form " << this->name << " destructor called" << std::endl << RESET;
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
       if (bureaucrat.getGrade() > this->signGrade)
            throw Form::GradeTooLowException();
        this->signedStatus = true;
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

Form *createForm(std::string name, int signGrade, int execGrade)
{
    try {
        Form *form = new Form(name, signGrade, execGrade);
        return (form);
    } catch (const std::exception &e) {
        std::cout << RED << "Error creating form: " << e.what() << std::endl << RESET;
        return (NULL);
    }
}
void deleteForm(Form *form)
{
    if (form == NULL)
        return;
    delete form;
}