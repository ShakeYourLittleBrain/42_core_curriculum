/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:17:15 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/07 20:47:57 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class AMateria;

class Cure : public AMateria {
	
	public:
		Cure();
		Cure(const Cure &copy);
		virtual ~Cure();

		Cure &operator=(const Cure &copy);

		virtual AMateria *clone() const;

		virtual std::string const &getType() const;
		virtual void use(ICharacter &target);
};

#endif
