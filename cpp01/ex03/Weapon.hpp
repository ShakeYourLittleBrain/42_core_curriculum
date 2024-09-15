/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 03:33:55 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/30 04:06:16 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
  private:
	std::string _type;

  public:
	Weapon(std::string type): _type(type) {}
	std::string const &getType();
	void setType(std::string type);
	~Weapon( void );
};

#endif
