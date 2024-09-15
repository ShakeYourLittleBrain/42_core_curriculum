/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 01:53:53 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/07 02:32:46 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
protected:
	std::string type;
public:
	virtual ~AAnimal() {} // we have to set it as virtual to avoid memory leaks with no body
	virtual const std::string& getType() const = 0;
	virtual void setType(const std::string& type) = 0;
	virtual void makeSound() const = 0;
};

#endif
