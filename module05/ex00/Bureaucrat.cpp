/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:45:22 by debs              #+#    #+#             */
/*   Updated: 2025/04/23 19:01:36 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    this.grade = 1;
    this.name = "random name";
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    this.name = name;
    try
    {
        grade < 1  && grade <= 150 ? throw Bureaucrat::GradeTooHighException() : this.grade = grade;
        grade > 150 ? throw Bureaucrat::GradeTooLowException() : this.grade;
    }
    catch(const std::exception& e)
        std::cerr << e.what() << std::endl;
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
        this->name = src.name;
    }
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

