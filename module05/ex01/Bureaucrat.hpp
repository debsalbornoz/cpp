/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:45:31 by debs              #+#    #+#             */
/*   Updated: 2025/05/05 09:08:59 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"
#define PURPLE    "\033[34m"
#define MAGENTA "\033[35m"

#include <string>
#include <exception>
#include <iostream>
#include <cstdlib>
#include "Form.hpp"

class Form;
class Bureaucrat
{
    private:
        const std::string name;
        int   grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &copy);
        std::string getName() const;
        int getGrade() const;
        void setGrade(int grade);
        void incrementGrade();
        void decrementGrade();
        bool signForm(Form &form);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Grade too high");
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Grade too low");
                }
        };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);
bool isNumber(std::string str);
int insertGrade();
void runMenu(Bureaucrat &b);
void displayMenu();

#endif