/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 02:15:35 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/08 18:33:16 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(" ")
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const std::string &type) : Animal(" ")
{
	this->type = type;
	std::cout << "Dog arg constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	if (this != &copy)
		Animal::operator=(copy);
	std::cout << "Dog assignment operator called" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof woof!" << std::endl;
}
