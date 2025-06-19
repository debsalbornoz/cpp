/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:29:26 by dlamark-          #+#    #+#             */
/*   Updated: 2025/06/19 17:33:44 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Menu{
	public:
		void runMenu(Bureaucrat &b);
		void displayMenu();
		int insertGrade();
		bool isNumber(std::string str);
};

#endif