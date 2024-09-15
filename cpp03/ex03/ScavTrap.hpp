/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 04:59:31 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/05 05:14:02 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

// Inherit publicly from ClapTrap with virtual keyword so that the DiamondTrap class can inherit from both FragTrap and ScavTrap only one set of the ClapTrap class attributes/methods

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap();

		ScavTrap &operator=(const ScavTrap &copy);

		void guardGate();
};

#endif
