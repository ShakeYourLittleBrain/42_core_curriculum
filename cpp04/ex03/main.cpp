/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 04:43:22 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/08 02:13:30 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main(void)
{
	IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		// src->learnMateria(new Ice());
		// src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp =  src->createMateria("ice");
		me->equip(tmp);
	tmp = src->createMateria("cure");
		me->equip(tmp);
	// tmp = src->createMateria("cure");
	// 	me->equip(tmp);
	// tmp = src->createMateria("ice");
	// 	me->equip(tmp);
	ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		// me->use(2, *bob);
		// me->use(3, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}

