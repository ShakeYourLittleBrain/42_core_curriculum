/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 01:53:10 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/04 23:08:30 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// This is the default constructor
ScavTrap::ScavTrap() : ClapTrap("Default")
{
	std::cout << "ScavTrap name: " << _name << " constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}
/*
	This is the constructor that takes a string as a parameter
	This is how we can set the name of the ScavTrap
	We call the constructor of the parent class ClapTrap with the name parameter
	We set the hit points to 100, the energy points to 50,
		and the attack damage to 20
*/
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap name: " << _name << " constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "ScavTrap assignation operator" << std::endl;
	if (this == &copy)
	{
		return (*this);
	}
	ClapTrap::operator=(copy);
	/*
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
	*/
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap name: " << _name << " destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode" << std::endl;
}
