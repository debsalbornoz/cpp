/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 08:56:16 by debs              #+#    #+#             */
/*   Updated: 2025/08/12 09:11:47 by debs             ###   ########.fr       */
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
    static AForm* makePardonForm(std::string target);
    static AForm* makeRobotomyForm(std::string target);
    static AForm* makeShrubberyForm(std::string target);
    AForm *makeForm(std::string name, std::string target);
    void deleteForm(AForm *&form);
};
#endif