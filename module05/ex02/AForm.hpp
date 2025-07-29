/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:58:56 by debs              #+#    #+#             */
/*   Updated: 2025/07/28 13:11:26 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        const std::string target;
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
        void checkGrade(int signGrade, int execGrade);
		virtual void execute(Bureaucrat const & executor) = 0;
        void setTarget(std::string target);

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