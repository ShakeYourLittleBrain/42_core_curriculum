/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:08:43 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/07 23:15:58 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class AMateria;

class IMateriaSource {

	public:
		virtual ~IMateriaSource() {}

		virtual void learnMateria(AMateria *materia) = 0;
		virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif
