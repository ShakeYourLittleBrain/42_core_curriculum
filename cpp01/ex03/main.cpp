/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 03:33:32 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/30 04:40:44 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

/*
In which case do you think it would be best to use a pointer to
Weapon? And a reference to Weapon? Why? Think about it before
starting this exercise.

Answer:
In the case of HumanA, it is better to use a reference to Weapon because
the weapon is mandatory for the HumanA object. If we use a pointer, we
have to check if the pointer is not NULL before using it.

In the case of HumanB, it is better to use a pointer to Weapon because
the weapon is not mandatory for the HumanB object. If we use a reference,
we have to initialize the weapon in the constructor, which is not always
necessary.
*/

int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
