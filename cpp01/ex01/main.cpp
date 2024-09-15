/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:07:56 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/30 06:56:56 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	Zombie	*horde;

	if (argc == 2)
		horde = zombieHorde(std::stoi(argv[1]), "Zombie");
	else
		horde = zombieHorde(5, "Zombie");
	delete[] horde;
	return (0);
}
