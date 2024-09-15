/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 01:53:53 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/07 01:44:18 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const std::string& type);
	Animal(const Animal& copy);

	// we have to set it as virtual to avoid memory leaks
	virtual ~Animal();

	Animal& operator=(const Animal& copy);

	const std::string& getType() const;
	void setType(const std::string& type);

	virtual void makeSound() const;

};

#endif
