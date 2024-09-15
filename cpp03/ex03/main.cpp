/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:49:43 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/05 06:23:06 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/**************************************************************************** */
/*          https://www.programiz.com/cpp-programming/inheritance             */
/**************************************************************************** */

int	main(void)
{
	std::cout << std::endl;
	DiamondTrap DiamondTrap("DiamondTrap");

	std::cout << std::endl;
	// This is my own test function
	// Test the toString function
	// The toString function should display the name, hit points, energy points, and attack damage of the ClapTrap
	// because the DiamondTrap class inherits from the ClapTrap class
	// because we haven't overridden the toString function in the DiamondTrap class next ex will do that
	std::cout << "Calling to string to see the initial values " << std::endl;
	DiamondTrap.toString();
	std::cout << std::endl;
	// Test the attack function this is and example of how to solve shadowing problem in diamond problem
	// In here, the attack function of the ScavTrap class is called
	// because we specified the class name before the function name (ScavTrap::attack) with scope resolution operator
	// We can also call the attack function of the FragTrap class by specifying the class name before the function name (FragTrap::attack)
	DiamondTrap.ScavTrap::attack("target");
	std::cout << std::endl;
	// Test the takeDamage function
	std::cout << std::endl;
	DiamondTrap.FragTrap::takeDamage(50);
	std::cout << std::endl;
	// Test the beRepaired function
	DiamondTrap.ClapTrap::beRepaired(20);
	std::cout << std::endl;
	// Test the guardGate function
	DiamondTrap.whoAmI();
	std::cout << std::endl;
	// When the program ends, the destructor will be called
	//it will call the destructor reverse order of the constructor
	std::cout << "Now the destructor reverse order of the constructor" << std::endl;
	return (0);
}

/*
 upon $> make
If we don't use the virtual keyword in the inheritance of the ScavTrap and FragTrap classes from the ClapTrap class, we will get the following error:

DiamondTrap.cpp:22:53: error: type 'ClapTrap' is not a direct or virtual base of 'DiamondTrap'
DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), _name(name) {
                                                    ^~~~~~~~
DiamondTrap.cpp:23:2: error: non-static member '_hitPoints' found in multiple base-class subobjects of type 'ClapTrap':
    class DiamondTrap -> class ScavTrap -> class ClapTrap
    class DiamondTrap -> class FragTrap -> class ClapTrap
        _hitPoints = FragTrap::_hitPoints;
        ^
./ClapTrap.hpp:23:15: note: member found by ambiguous name lookup
        unsigned int _hitPoints;
                     ^
DiamondTrap.cpp:24:2: error: non-static member '_energyPoints' found in multiple base-class subobjects of type 'ClapTrap':
    class DiamondTrap -> class ScavTrap -> class ClapTrap
    class DiamondTrap -> class FragTrap -> class ClapTrap
        _energyPoints = ScavTrap::_energyPoints;
        ^
./ClapTrap.hpp:24:15: note: member found by ambiguous name lookup
        unsigned int _energyPoints;
                     ^
DiamondTrap.cpp:25:2: error: non-static member '_attackDamage' found in multiple base-class subobjects of type 'ClapTrap':
    class DiamondTrap -> class ScavTrap -> class ClapTrap
    class DiamondTrap -> class FragTrap -> class ClapTrap
        _attackDamage = FragTrap::_attackDamage;
        ^
./ClapTrap.hpp:25:15: note: member found by ambiguous name lookup
        unsigned int _attackDamage;
                     ^
DiamondTrap.cpp:34:12: error: ambiguous conversion from derived class 'DiamondTrap' to base class 'ClapTrap':
    class DiamondTrap -> class ScavTrap -> class ClapTrap
    class DiamondTrap -> class FragTrap -> class ClapTrap
        ClapTrap::_name = copy._name + "_clap_name";
                  ^~~~~
DiamondTrap.cpp:36:2: error: non-static member '_hitPoints' found in multiple base-class subobjects of type 'ClapTrap':
    class DiamondTrap -> class ScavTrap -> class ClapTrap
    class DiamondTrap -> class FragTrap -> class ClapTrap
        _hitPoints = copy._hitPoints;
        ^
./ClapTrap.hpp:23:15: note: member found by ambiguous name lookup
        unsigned int _hitPoints;
                     ^
DiamondTrap.cpp:37:2: error: non-static member '_energyPoints' found in multiple base-class subobjects of type 'ClapTrap':
    class DiamondTrap -> class ScavTrap -> class ClapTrap
    class DiamondTrap -> class FragTrap -> class ClapTrap
        _energyPoints = copy._energyPoints;
        ^
./ClapTrap.hpp:24:15: note: member found by ambiguous name lookup
        unsigned int _energyPoints;
                     ^
DiamondTrap.cpp:38:2: error: non-static member '_attackDamage' found in multiple base-class subobjects of type 'ClapTrap':
    class DiamondTrap -> class ScavTrap -> class ClapTrap
    class DiamondTrap -> class FragTrap -> class ClapTrap
        _attackDamage = copy._attackDamage;
        ^
./ClapTrap.hpp:25:15: note: member found by ambiguous name lookup
        unsigned int _attackDamage;
                     ^
DiamondTrap.cpp:47:2: error: non-static member '_hitPoints' found in multiple base-class subobjects of type 'ClapTrap':
    class DiamondTrap -> class ScavTrap -> class ClapTrap
    class DiamondTrap -> class FragTrap -> class ClapTrap
        _hitPoints = copy._hitPoints;
        ^
./ClapTrap.hpp:23:15: note: member found by ambiguous name lookup
        unsigned int _hitPoints;
                     ^
DiamondTrap.cpp:48:2: error: non-static member '_energyPoints' found in multiple base-class subobjects of type 'ClapTrap':
    class DiamondTrap -> class ScavTrap -> class ClapTrap
    class DiamondTrap -> class FragTrap -> class ClapTrap
        _energyPoints = copy._energyPoints;
        ^
./ClapTrap.hpp:24:15: note: member found by ambiguous name lookup
        unsigned int _energyPoints;
                     ^
DiamondTrap.cpp:49:2: error: non-static member '_attackDamage' found in multiple base-class subobjects of type 'ClapTrap':
    class DiamondTrap -> class ScavTrap -> class ClapTrap
    class DiamondTrap -> class FragTrap -> class ClapTrap
        _attackDamage = copy._attackDamage;
        ^
./ClapTrap.hpp:25:15: note: member found by ambiguous name lookup
        unsigned int _attackDamage;
                     ^
DiamondTrap.cpp:55:82: error: ambiguous conversion from derived class 'DiamondTrap' to base class 'ClapTrap':
    class DiamondTrap -> class ScavTrap -> class ClapTrap
    class DiamondTrap -> class FragTrap -> class ClapTrap
        std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
                                                                                        ^~~~~
12 errors generated.
make: *** [DiamondTrap.o] Error 1
*/
