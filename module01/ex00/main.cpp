/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:30:52 by dlamark-          #+#    #+#             */
/*   Updated: 2024/12/26 15:18:31 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie my_zombie("Zombie 1");
	my_zombie.announce();

	Zombie* zombie = newZombie("Zombie 2");
	zombie->announce();
	
	randomChump("Zombie 3");
	
	delete zombie;
	return (0);
}