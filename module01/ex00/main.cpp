/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:30:52 by dlamark-          #+#    #+#             */
/*   Updated: 2024/12/09 17:10:01 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string zombie_name = "";
	
	std::cout << "Enter zombie name: ";
	std::getline(std::cin, zombie_name);
	Zombie my_zombie(zombie_name);

	my_zombie.announce();
}