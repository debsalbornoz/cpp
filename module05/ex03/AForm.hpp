/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:58:56 by debs              #+#    #+#             */
/*   Updated: 2025/08/11 17:57:00 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool signedStatus;
        const int signGrade;
        const int execGrade;
    public:
        AForm(void);
        AForm(std::string name, int signGrade, int execGrade);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        virtual ~AForm(void);
        std::string getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool getSignedStatus() const;
        void beSigned(Bureaucrat &bureaucrat);
        void Sign(Bureaucrat &bureaucrat, AForm &f);
        void checkGrade(int signGrade, int execGrade);
        virtual void execute(Bureaucrat const & executor) const = 0;
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
    class FormNotSignedException : public std::exception{
        public:
            virtual const char *what() const throw()
            {
                return ("Form is not signed");
            }
    };

};

std::ostream& operator<<(std::ostream& out, const AForm& Aform);
AForm *createAForm(std::string name, int signGrade, int execGrade);
void deleteAForm(AForm *form);

#endif/*

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
        AForm(void);
        AForm(std::string name, int signGrade, int execGrade);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        ~AForm(void);
        std::string getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool getSignedStatus() const;
        void beSigned(Bureaucrat &bureaucrat);
        void checkGrade(int signGrade, int execGrade);
		virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif

*/