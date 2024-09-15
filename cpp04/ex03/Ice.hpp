/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:22:10 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/07 23:48:41 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class AMateria;

class Ice : public AMateria {

	public:
		Ice();
		Ice(std::string const &type);
		Ice(const Ice &copy);
		virtual ~Ice();

		Ice &operator=(const Ice &copy);

		virtual AMateria *clone() const;

		virtual std::string const &getType() const;
		virtual void use(ICharacter &target);
};



# endif
