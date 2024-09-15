/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:56:37 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/07 23:16:36 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class AMateria;
class IMateriaSource;

class MateriaSource : public IMateriaSource {

	private:
		AMateria *_materia[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource();
		
		MateriaSource &operator=(const MateriaSource &other);

		void learnMateria(AMateria *materia);
		AMateria *createMateria(const std::string &type);
};

#endif
