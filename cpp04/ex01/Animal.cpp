/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 01:54:08 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/06 04:10:01 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Default_Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string& a_Type) : type(a_Type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& copy)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &copy)
	{
		type = copy.type;
	}
	return *this;
}

const std::string& Animal::getType() const
{
	std::cout << "Animal type getter called" << std::endl;
	return type;
}

void Animal::setType(const std::string& type)
{
	std::cout << "Animal type setter called" << std::endl;
	this->type = type;
}

void Animal::makeSound() const
{
	std::cout << "Animal can't make sound" << std::endl;
}
