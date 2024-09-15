/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 02:15:31 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/07 02:25:17 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
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
	const std::string& getType() const;
	void setType(const std::string& type);
};

#endif
