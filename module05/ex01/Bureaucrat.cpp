/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:45:22 by debs              #+#    #+#             */
/*   Updated: 2025/08/11 16:34:09 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150)
{
std::cout << GREEN << "Bureaucrat " << this->name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
	std::cout << GREEN << "Bureaucrat " << this->name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		this->grade = src.grade;
	}
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat " << this->name << " destructor called" << std::endl << RESET;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &Bureaucrat)
{
	os << PURPLE << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl << RESET;
	return os;
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	try{
		this->setGrade(this->grade - 1);
	} catch (const std::exception& e) {
		std::cout << RED <<"Bureaucrat " << this->name << " could not be incremented because: " << e.what() << std::endl << RESET;
		return;
	}
	std::cout << GREEN << "Bureaucrat " << this->name << " incremented" << std::endl;
}

void Bureaucrat::decrementGrade()
{
	try {
		this->setGrade(this->grade + 1);
	} catch (const std::exception& e) {
		std::cout << RED << "Bureaucrat " << this->name << " could not be decremented because: " << e.what() << std::endl << RESET;
		return;
	}
	std::cout << GREEN << "Bureaucrat " << this->name << " decremented" << std::endl << RESET;
}

void Bureaucrat::setGrade(int grade)
{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat* createBureaucrat(const std::string name, int grade) {
	try {
		Bureaucrat *b = new Bureaucrat(name, grade);
		std::cout << "Successfully created: " << *b << std::endl;
		return (b);
	} catch (const std::exception& e) {
		std::cout << RED << "Error creating " << name << ": " << e.what() << RESET << std::endl;
		return (NULL);
	}
}

void deleteBureaucrat(Bureaucrat* bureaucrat) {
	if (bureaucrat) {
		delete bureaucrat;
		std::cout << RED << "Bureaucrat deleted" << std::endl << RESET;
	} else {
		std::cout << RED << "Bureaucrat not found" << std::endl << RESET;
	}
}

void Bureaucrat::signForm(Form &form)
{
    try {
        form.beSigned(*this);
    } catch (const std::exception &e) {
        std::cout << RED << this->getName() << " could not sign " << form.getName() << " because " << e.what() << std::endl << RESET;
        return;
    }
    std::cout << GREEN << this->getName() << " signed " << form.getName() << std::endl << RESET;
}

/*
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150)
{
std::cout << "Bureaucrat " << this->name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	try{
		checkGrade(grade);
	}
	catch (const std::exception &e) {
			std::cout << RED <<e.what() << std::endl << RESET;
			return;
		}
	this->grade = grade;
	std::cout << "Bureaucrat " << this->name << " constructor called" << std::endl;
}

void Bureaucrat::checkGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		this->grade = src.grade;
	}
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->name << " destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &Bureaucrat)
{
	os << GREEN << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl << RESET;
	return os;
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	try {
		checkGrade(this->grade - 1);
	} catch (const std::exception &e) {
		std::cout << RED << e.what() << std::endl << RESET;
		return;
	}
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
		try {
			checkGrade(this->grade + 1);
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl << RESET;
			return;
		}  
	this->grade++;
}

void Bureaucrat::setGrade(int grade)
{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

void Bureaucrat::signForm(Form &form)
{
    try {
        form.beSigned(*this);
    } catch (const std::exception &e) {
        std::cout << RED << this->getName() << " could not sign " << form.getName() << " because " << e.what() << std::endl << RESET;
        return;
    }
    std::cout << GREEN << this->getName() << " signed " << form.getName() << std::endl << RESET;
}

*/