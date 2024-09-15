/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 01:54:08 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/08 18:33:49 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default_WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &a_Type) : type(a_Type)
{
	std::cout << "WrongAnimal arg constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &copy)
		type = copy.type;
	return (*this);
}

const std::string &WrongAnimal::getType() const
{
	std::cout << "WrongAnimal type getter called" << std::endl;
	return (type);
}

void WrongAnimal::setType(const std::string &type)
{
	std::cout << "WrongAnimal type setter called" << std::endl;
	this->type = type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal can't make sound" << std::endl;
}
