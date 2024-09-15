/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 04:46:22 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/07 23:17:11 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class AMateria;
class ICharacter;

class Character : public ICharacter {

	private:
		std::string _name;
		AMateria *_inventory[4];

	public:
		Character();
		Character(const std::string &name);
		Character(const Character &copy);
		~Character();

		Character &operator=(const Character &copy);

		virtual const std::string &getName() const;

		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);


		void setName(const std::string &name);
		AMateria *getInventory(int idx) const;
		void setInventory(int idx, AMateria *materia);
};

# endif
