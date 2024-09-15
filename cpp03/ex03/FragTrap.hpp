/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:59:49 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/05 05:14:05 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

// Inherit publicly from ClapTrap with virtual keyword so that the DiamondTrap class can inherit from both FragTrap and ScavTrap only one set of the ClapTrap class attributes/methods

class FragTrap : virtual public ClapTrap
{
  public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &copy);
	~FragTrap();

	FragTrap &operator=(const FragTrap &copy);

	void highFivesGuys( void );
};

#endif
