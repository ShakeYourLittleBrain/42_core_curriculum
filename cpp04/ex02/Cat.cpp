/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 01:54:51 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/07 02:25:01 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const std::string& type){
	this->type = type;
	this->_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& copy){
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*copy._brain);
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& copy) {
	if (this != &copy) {
		this->type = copy.type;
		delete _brain;
		_brain = new Brain(*copy._brain);
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow Meow!" << std::endl;
}

const std::string& Cat::getType() const {
	return this->type;
}

void Cat::setType(const std::string& type) {
	this->type = type;
}
