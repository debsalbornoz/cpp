/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:21:02 by dlamark-          #+#    #+#             */
/*   Updated: 2024/12/26 14:55:20 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie 
{
	private:
		std::string name;
	public:
		Zombie(std::string zombie_name);
		~Zombie();
		void announce(void);
};

Zombie *newZombie( std::string name );
void	randomChump(std::string name);

#endif
