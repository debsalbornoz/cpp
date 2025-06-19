/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:51:49 by debs              #+#    #+#             */
/*   Updated: 2025/06/19 18:09:47 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("Alice", 2);
		std::cout << b1 << std::endl;

		b1.incrementGrade();
		std::cout << "After increment: " << b1 << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << RED <<  e.what() << std::endl << RESET;
	}

	try {
		Bureaucrat b2("Bob", 149);
		std::cout << b2 << std::endl;

		b2.decrementGrade();
		std::cout << "After decrement: " << b2 << std::endl;

		b2.decrementGrade();
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	try {
		Bureaucrat b3("Charlie", 0);
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}

	try {
		Bureaucrat b4("Dave", 151);
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << std::endl << RESET;
	}

	return 0;
}