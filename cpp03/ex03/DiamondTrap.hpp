/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 02:48:18 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/05 05:09:19 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// It may inherit multiple instances of the base ClapTrap class. This is known as the diamond problem.
// To solve this problem, we can use virtual inheritance. This means that the base class is inherited only once.

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap &copy);
		~DiamondTrap();

		DiamondTrap &operator=(const DiamondTrap &copy);

		void whoAmI();
};



# endif
