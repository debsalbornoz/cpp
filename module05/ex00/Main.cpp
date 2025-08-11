/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:51:49 by debs              #+#    #+#             */
/*   Updated: 2025/08/11 16:27:05 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

	std::cout << "\n---- Creating Bureaucrats ----" << std::endl;
	Bureaucrat *a = createBureaucrat("Alice", 2);
	Bureaucrat *b = createBureaucrat("Bob", 149);
	Bureaucrat *c = createBureaucrat("Charlie", 0);
	Bureaucrat *d = createBureaucrat("Dave", 151);

	std::cout << "\n---- Trying to Increment/Decrement Bureaucrat ----" << std::endl;
	if (a != NULL)
	{
		a->incrementGrade();
		a->incrementGrade();
	}
	if (b != NULL)
		b->decrementGrade();
	if (c != NULL)
		c->decrementGrade();
	if (d != NULL)
		d->decrementGrade();

	std::cout << "\n---- Bureaucrats after operations ----" << std::endl;
	if (a != NULL)
		std::cout << *a;
	if (b != NULL)
		std::cout << *b;
	if (c != NULL)
		std::cout << *c;

	std::cout << "\n---- Deleting Bureaucrats ----" << std::endl;
	deleteBureaucrat(a);
	deleteBureaucrat(b);
	deleteBureaucrat(c);
	deleteBureaucrat(d);
	return 0;
}
