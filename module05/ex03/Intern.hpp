/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 08:56:16 by debs              #+#    #+#             */
/*   Updated: 2025/08/11 09:58:44 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern {
    public:
    Intern(void);
    Intern(std::string target);
    Intern(Intern const & src);
    ~Intern(void);
    Intern& operator=(Intern const &rhs);
    AForm* makePardonForm(std::string target);
    AForm* makeRobotomyForm(std::string target);
    AForm* makeShrubberyForm(std::string target);
    AForm *makeForm(std::string name, std::string target);
    void deleteForm(AForm *form);
};
#endif