/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 04:52:19 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/08 02:10:47 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(){
	_type = "ice";
}

Ice::Ice(std::string const &type) {
	_type = type;
	if (DEBUG)
		std::cout << "Ice arg constructor called" << std::endl;
}

Ice::Ice(const Ice &copy) {
	_type = copy._type;
	if (DEBUG)
		std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice() {
	if (DEBUG)
		std::cout << "Ice destructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &copy) {
	if (this != &copy) {
		_type = copy._type;
		if (DEBUG)
			std::cout << "Ice assignation operator called" << std::endl;
	}
	return *this;
}

AMateria *Ice::clone() const {
	if (DEBUG)
		std::cout << "Ice clone called" << std::endl;
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

std::string const &Ice::getType() const {
	return _type;
}
