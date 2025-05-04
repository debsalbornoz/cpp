/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:58:56 by debs              #+#    #+#             */
/*   Updated: 2025/05/04 18:30:26 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool signedStatus;
        const int signGrade;
        const int execGrade;
    public:
        Form(void);
        Form(std::string name, int signGrade, int execGrade);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        ~Form(void);
        std::string getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool getSignedStatus() const;
        void beSigned(Bureaucrat &bureaucrat);
        void Sign(Bureaucrat &bureaucrat, Form &f);

    class GradeTooHighException : public std::exception{
        public:
            virtual const char *what() const throw()
            {
                return ("Grade too high");
            }
            
    };
    class GradeTooLowException : public std::exception{
        public:
            virtual const char *what() const throw()
            {
                return ("Grade too low");
            }
    };

};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif