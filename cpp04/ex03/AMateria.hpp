/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:50:33 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/08 02:14:44 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

# define DEBUG 0

class ICharacter;

class AMateria {

	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(const std::string &type);
		virtual ~AMateria();

		virtual std::string const &getType() const;

		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};


#endif
