/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 01:54:39 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/08 18:31:28 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
	WrongCat();
	WrongCat(const std::string &type);
	WrongCat(const WrongCat& copy);
	~WrongCat();

	WrongCat& operator=(const WrongCat& copy);

	void makeSound() const;
};

#endif
