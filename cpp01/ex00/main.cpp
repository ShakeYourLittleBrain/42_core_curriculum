/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:51:59 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/29 03:46:19 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int	main(void)
{
	Zombie	*zombie2;

	randomChump("Stack");

	std::cout << "creating heap object: " << zombie2 << std::endl;
	zombie2 = newZombie("Heap");
	zombie2->announce();
	delete	zombie2;
	return (0);
}
