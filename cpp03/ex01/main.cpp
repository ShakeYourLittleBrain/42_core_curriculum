/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:49:43 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/04 05:27:26 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/**************************************************************************** */
/*          https://www.programiz.com/cpp-programming/inheritance             */
/**************************************************************************** */

int	main(void)
{
	std::cout << std::endl;
	ScavTrap scavTrap("ScavTrap");

	std::cout << std::endl;
	// Test the toString function
	// The toString function should display the name, hit points, energy points, and attack damage of the ClapTrap
	// because the ScavTrap class inherits from the ClapTrap class
	// because we haven't overridden the toString function in the ScavTrap class next ex will do that
	std::cout << "Calling to string to see the initial values " << std::endl;
	scavTrap.toString();
	std::cout << std::endl;
	// Test the attack function
	scavTrap.attack("Target");
	std::cout << std::endl;
	// Test the takeDamage function
	std::cout << std::endl;
	scavTrap.takeDamage(50);
	std::cout << std::endl;
	// Test the beRepaired function
	scavTrap.beRepaired(20);
	std::cout << std::endl;
	// Test the guardGate function
	scavTrap.guardGate();
	std::cout << std::endl;
	// When the program ends, the destructor will be called
	//it will call the destructor reverse order of the constructor
	std::cout << "Now the destructor reverse order of the constructor" << std::endl;
	return (0);
}
