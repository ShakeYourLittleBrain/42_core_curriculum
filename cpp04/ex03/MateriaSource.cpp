/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 04:50:19 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/08 02:11:19 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	if (DEBUG)
		std::cout << "MateriaSource Default Constructor called." << std::endl;
	for (int i = 0; i < 4; i++) {
		_materia[i] = NULL;
	}
}

/*
with clone we make sure that we are not copying the same object
we are creating a new object with the same values
we are not copying the address of the object
so it is not a shallow copy
*/

MateriaSource::MateriaSource(const MateriaSource &copy) {
	if (DEBUG)
		std::cout << "MateriaSource Copy Constructor called." << std::endl;
	for (int i = 0; i < 4; i++) {
		if (copy._materia[i] != NULL) {
			_materia[i] = copy._materia[i]->clone();
		} else {
			_materia[i] = NULL;
		}
	}
}

MateriaSource::~MateriaSource() {
	if (DEBUG)
		std::cout << "MateriaSource Destructor called." << std::endl;
	for (int i = 0; i < 4; i++) {
		delete _materia[i];
	}
}

/*
	same as copy constructor
	we are not copying the address of the object
	so it is not a shallow copy
*/

MateriaSource &MateriaSource::operator=(const MateriaSource &copy) {
	if (DEBUG)
		std::cout << "MateriaSource Assignation operator called." << std::endl;
	if (this != &copy) {
		for (int i = 0; i < 4; i++) {
			delete _materia[i];
			if (copy._materia[i] != NULL) {
				_materia[i] = copy._materia[i]->clone();
			} else {
				_materia[i] = NULL;
			}
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (DEBUG)
		std::cout << "Materia type: [" << materia->getType() << "] learned." << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_materia[i] == NULL) {
			_materia[i] = materia;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	if (DEBUG)
		std::cout << "Materia type: [" << type << "] created." << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_materia[i] != NULL && _materia[i]->getType() == type) {
			return _materia[i];
		}
	}
	return NULL;
}
