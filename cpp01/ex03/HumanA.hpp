/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 03:34:25 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/01 01:13:08 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

/*
Weapon & (Reference to Weapon)
Syntax: Weapon &ref
Meaning: ref is a reference to an existing Weapon object.
Initialization: Must be initialized when declared.
Nullability: Cannot be null; must always refer to a valid object.
Reassignment: Cannot be reassigned to refer to another object after initialization.
Usage: Often used for syntactic convenience and to ensure the referenced object is valid.
*/

class HumanA
{
	private:
		std::string _name;
		Weapon &_weapon;

	public:
		HumanA(const std::string& name, Weapon& weapon) : _name(name), _weapon(weapon) {}
		~HumanA( void ){}
		void attack();
};

#endif
