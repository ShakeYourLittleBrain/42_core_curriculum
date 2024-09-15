/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:49:29 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/04 05:28:54 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap name: " << _name << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap name: " << _name << " destructor called" << std::endl;
}

/*
 Ancopy way to implement the copy constructor is to use the member initializer list to initialize the member variables
ClapTrap::ClapTrap(const ClapTrap &copy) {
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}
*/
ClapTrap::ClapTrap(const ClapTrap &copy) : _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy) {
	if (this == &copy) {
		return *this;
	}
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
	return *this;
}

/*
	When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
	When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
		cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
		or energy points left.
*/
void ClapTrap::attack(const std::string &target) {
	// If the ClapTrap is already destroyed, do nothing there are 2 cases to consider:
	// A ClapTrap is destroyed if its hit points are 0
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
		return;
	}
	// A ClapTrap is out of energy if its energy points are 0
	else if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	// If the ClapTrap is already destroyed, do nothing there are 2 cases to consider:
	// A ClapTrap is destroyed if its hit points are 0
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
		return;
	}
	// A ClapTrap is out of energy if its energy points are 0
	else if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
		return;
	}
	// If the damage is greater than or equal to the hit points, set hit points to 0 and print a message
	// copywise, subtract the damage from the hit points and print a message
	if (amount >= _hitPoints) {
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage and is destroyed!" << std::endl;
	} else {
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage and now has " << _hitPoints << " hit points." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	// If the ClapTrap is already destroyed, do nothing there are 2 cases to consider:
	// A ClapTrap is destroyed if its hit points are 0
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is destroyed and cannot be repaired!" << std::endl;
		return;
	}
	// A ClapTrap is out of energy if its energy points are 0
	else if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
		return;
	}
	// Subject says that energy points should be consumed when repairing and attack , so decrement energy points
	_energyPoints--;

	// If the hit points are already at 10, do nothing and print a message
	if (_hitPoints == 10) {
		std::cout << "ClapTrap " << _name << " is already at full health!" << std::endl;
		return;
	}
	// If the hit points plus the amount to repair is greater than 10, set hit points to 10 and print a message
	// copywise, add the amount to the hit points and print a message
	if (_hitPoints + amount > 10) {
		_hitPoints = 10;
		std::cout << "ClapTrap " << _name << " is repaired to full health!" << std::endl;
	} else {
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points and now has " << _hitPoints << " hit points." << std::endl;
	}
}

// Print the ClapTrap's name, hit points, energy points, and attack damage
void ClapTrap::toString() const {
	std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points, " << _energyPoints << " energy points and " << _attackDamage << " attack damage." << std::endl;
}


// Getter for _name
const std::string &ClapTrap::getName() const {
	return _name;
}

// Setter for _name
void ClapTrap::setName(const std::string& name) {
	_name = name;
}

// Getter for _hitPoints
int ClapTrap::getHitPoints() const {
	return _hitPoints;
}

// Setter for _hitPoints
void ClapTrap::setHitPoints(int hitPoints) {
	_hitPoints = hitPoints;
}

// Getter for _energyPoints
int ClapTrap::getEnergyPoints() const {
	return _energyPoints;
}

// Setter for _energyPoints
void ClapTrap::setEnergyPoints(int energyPoints) {
	_energyPoints = energyPoints;
}

// Getter for _attackDamage
int ClapTrap::getAttackDamage() const {
	return _attackDamage;
}

// Setter for _attackDamage
void ClapTrap::setAttackDamage(int attackDamage) {
	_attackDamage = attackDamage;
}
