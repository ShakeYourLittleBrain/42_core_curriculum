/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:49:43 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/04 05:26:09 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/******************************************************************************/
/*          https://www.programiz.com/cpp-programming/object-class            */
/******************************************************************************/

int main()
{
	ClapTrap clapTrap("ClapTrap1");
	clapTrap.attack("Target1");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(1);

	std::cout << std::endl;

	ClapTrap clapTrap3 = clapTrap;
	clapTrap3.setName("ClapTrap2");
	clapTrap3.attack("Target2");
	std::cout << "ClapTrap name: " << clapTrap3.getName() << " Should fail"  <<std::endl;
	clapTrap3.attack("Target11");

	std::cout << std::endl;
	ClapTrap *clapTrap4 = new ClapTrap("ClapTrap3");
	clapTrap4->attack("Target1");
	clapTrap4->attack("Target2");
	clapTrap4->attack("Target3");
	clapTrap4->attack("Target4");
	clapTrap4->attack("Target5");
	clapTrap4->attack("Target6");
	clapTrap4->attack("Target7");
	clapTrap4->attack("Target8");
	clapTrap4->attack("Target9");
	clapTrap4->attack("Target10");
	std::cout << "ClapTrap name: " << clapTrap4->getName() << " attack 11 Should fail"  <<std::endl;
	clapTrap4->attack("Target11");
	std::cout << std::endl;
	delete clapTrap4;

	return (0);
}
