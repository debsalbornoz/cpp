/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:51:49 by debs              #+#    #+#             */
/*   Updated: 2025/05/04 10:54:13 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::string name;
    int grade;

    std::cout << PURPLE <<"Insert name:" << std::endl << RESET;
    std::cin >> name;
    std::cin.ignore();
    grade = insertGrade();
    try{
        Bureaucrat b(name, grade);
        runMenu(b);
    } catch (const std::exception &e) {
        std::cout << RED << e.what() << std::endl << RESET;
        return (-1);
    }
    return (0);
}