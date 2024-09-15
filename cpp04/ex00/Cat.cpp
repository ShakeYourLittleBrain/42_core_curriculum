/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 01:54:51 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/06 03:54:27 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(" ") {
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const std::string& type) : Animal(" ") {
	this->type = type;
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& copy) {
	if (this != &copy) {
		Animal::operator=(copy);
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow Meow!" << std::endl;
}
