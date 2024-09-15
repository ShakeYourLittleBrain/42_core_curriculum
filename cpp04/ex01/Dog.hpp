/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 02:15:31 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/07 00:56:41 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
  private:
	Brain *_brain;

  public:
	Dog();
	Dog(const std::string &type);
	Dog(const Dog& copy);
	~Dog();

	Dog& operator=(const Dog& copy);

	void makeSound() const;
};

#endif
