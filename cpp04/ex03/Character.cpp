/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 04:46:18 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/08 02:09:25 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	this->_name = "";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string &_name) : _name(_name)
{
	if (DEBUG)
		std::cout << "Character type: " << _name << " is born." << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::~Character()
{
	if (DEBUG)
		std::cout << _name << " is dead." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			_inventory[i] = NULL;
	}
}

Character::Character(const Character &copy)
{
	_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i] != NULL)
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	if (DEBUG)
		std::cout << "Character " << _name << " has been cloned." << std::endl;
}

Character &Character::operator=(const Character &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		for (int i = 0; i < 4; i++)
		{
			if (copy._inventory[i] != NULL)
				_inventory[i] = copy._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	if (DEBUG)
		std::cout << "Character " << _name << " has been assigned." << std::endl;
	return (*this);
}


void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			if (DEBUG)
				std::cout << "AMateria type: [" << _name << "] is equipped " << m->getType() << std::endl;
			return ;
		}
	}
	if (DEBUG)
		std::cout << "Failed to add " << m->getType() << " to _inventory of " << _name << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		if (DEBUG)
			std::cout << _name << ": index is out of bound (" << idx << ")" << std::endl;
		return ;
	}
	else if (_inventory[idx] == NULL)
	{
		if (DEBUG)
			std::cout << "Character type: [" << _name << "] there is nothing to unequip (" << idx << ")" << std::endl;
		return ;
	}
	_inventory[idx] = NULL;
	if (DEBUG)
		std::cout << _name << " successfully unequipped " << _inventory[idx]->getType() << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
	{
		if (DEBUG)
			std::cout << "Character type [" << _name << " -> use] index is out of bound (" << idx << ")" << std::endl;
		return ;
	}
	else if (_inventory[idx] == NULL)
	{
		if (DEBUG)
			std::cout << "Character type [" << _name << " -> use] there is nothing to use (" << idx << ")" << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}

// Getters and Setters

const std::string &Character::getName() const
{
	return (_name);
}

void Character::setName(const std::string &name)
{
	_name = name;
}

AMateria *Character::getInventory(int idx) const
{
	return (_inventory[idx]);
}

void Character::setInventory(int idx, AMateria *materia)
{
	_inventory[idx] = materia;
}
