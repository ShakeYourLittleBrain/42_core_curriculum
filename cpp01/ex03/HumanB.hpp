/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 03:57:49 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/01 01:19:01 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

/*
Weapon * (Pointer to Weapon)
Syntax: Weapon *ptr
Meaning: ptr is a pointer that can hold the address of a Weapon object.
Initialization: Can be initialized to nullptr or any valid address.
Nullability: Can be null, meaning it may point to no object.
Reassignment: Can be reassigned to point to different Weapon objects.
Usage: Provides more flexibility, allowing dynamic memory management and
	the ability to point to different objects during the program's execution.
*/

class HumanB
{
  private:
	std::string _name;
	Weapon *_weapon;

  public:
	HumanB(const std::string& name) : _name(name), _weapon(NULL) {}
	~HumanB( void ){}
	void setWeapon(Weapon& weapon);
	void attack();
};

#endif
