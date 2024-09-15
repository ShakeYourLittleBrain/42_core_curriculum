/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 05:13:33 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/08 02:07:49 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	if (DEBUG)
		std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {
	if (DEBUG)
		std::cout << "AMateria " << type <<  " Constructor called" << std::endl;
}

AMateria::~AMateria() {
	if (DEBUG)
		std::cout << "AMateria Destructor called" << std::endl;
}

std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter &target) {
	if (DEBUG)
		std::cout << "Using " << _type << " on " << target.getName() << std::endl;
}
