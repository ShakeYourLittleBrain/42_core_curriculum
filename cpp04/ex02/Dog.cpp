/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 02:15:35 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/07 02:28:31 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const std::string& type){
	this->type = type;
	this->_brain = new Brain();
	std::cout << "Dog arg constructor called" << std::endl;
}

Dog::Dog(const Dog& copy){
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*copy._brain);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog& Dog::operator=(const Dog& copy) {
	if (this != &copy) {
		this->type = copy.type;
		delete _brain;
		_brain = new Brain(*copy._brain);
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof!" << std::endl;
}

const std::string& Dog::getType() const {
	return this->type;
}

void Dog::setType(const std::string& type) {
	this->type = type;
}
