/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 04:52:30 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/08 02:10:07 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(){
	_type = "cure";
	if (DEBUG)
		std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &copy){
	_type = copy._type;
	if (DEBUG)
	 std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure() {
	if (DEBUG)
		std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &copy) {
	if (this != &copy) {
		_type = copy._type;
		if (DEBUG)
			std::cout << "Cure assignation operator called" << std::endl;
	}
	return *this;
}

AMateria *Cure::clone() const {
	if (DEBUG)
		std::cout << "Cure clone called" << std::endl;
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

std::string const &Cure::getType() const {
	return _type;
}
