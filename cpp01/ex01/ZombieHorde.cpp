/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:07:22 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/29 20:04:52 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* horde = new Zombie[N];

	for(int i = 0; i < N; i++)
	{
		horde[i].setName(name + "_" + std::to_string(i));
		horde[i].announce();
	}
	return horde;
}
