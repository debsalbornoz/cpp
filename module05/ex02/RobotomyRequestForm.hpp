/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:57:08 by debs              #+#    #+#             */
/*   Updated: 2025/08/10 17:12:15 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string target;
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
        void execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & rhs);
#endif