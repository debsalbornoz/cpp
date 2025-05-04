/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:45:22 by debs              #+#    #+#             */
/*   Updated: 2025/05/04 10:54:14 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Bureaucrat"), grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
    std::cout << "Bureaucrat constructor called" << std::endl;
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
    std::cout << "Bureaucrat destructor called" << std::endl;
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
        if (this->grade - 1 < 1)
            throw Bureaucrat::GradeTooHighException();
    } catch (const std::exception &e) {
        std::cout << RED << e.what() << std::endl << RESET;
        return;
    }
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    try {
        if (this->grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();   
    } catch (const std::exception &e) {
        std::cout << RED <<  e.what() << std::endl << RESET;
        return;
    }
    this->grade++;
}

void Bureaucrat::setGrade(int grade)
{
    try {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
    } catch (const std::exception &e) {
        std::cout << RED <<e.what() << std::endl << RESET;
        return;
    }
    this->grade = grade;
}

bool isNumber(std::string str)
{
    if (str.empty())
        return (false);
    int i = 0;
    if (str[i] == '-')
        i = 1;
    for (size_t j = i;  j < str.length(); j++)
    {
        if (!isdigit(str[j]))
            return (false);
    }
    return (true);
}

int insertGrade()
{
    std::string grade;
    
    while (1)
    {
        std::cout << PURPLE << "Insert grade:" << std::endl << RESET;
        std::getline(std::cin, grade);
        if (isNumber(grade))
        {
            return (atoi(grade.c_str()));
        }
        else
            std::cout << RED << "Invalid input" << std::endl << RESET;
    }
}

void displayMenu()
{
    std::cout << PURPLE << "Select action:" << std::endl;
    std::cout << "1 - Increment grade" << std::endl;
    std::cout << "2 - Decrement grade" << std::endl;
    std::cout << "3 - Set grade" << std::endl;
    std::cout << "4 - Display information" << std::endl;
    std::cout << "5 - Exit" << std::endl << RESET;
}

void runMenu(Bureaucrat &b)
{
    bool running = true;
    std::string action = "";
    while(running)
    {
        displayMenu();
        std::getline(std::cin, action);
        if (action == "1")
            b.incrementGrade();
        else if (action == "2")
            b.decrementGrade();
        else if (action == "3")
        {
            int grade = insertGrade();
            b.setGrade(grade);
        }
        else if (action == "4")
            std::cout << b << std::endl;
        else if (action == "5")
            running = false;
        else if (action != "5")
            std::cout << RED << "Invalid action. Please enter a valid action.\n" << RESET;
    }
    
}