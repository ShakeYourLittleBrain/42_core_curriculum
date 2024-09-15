/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 01:53:53 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/06 03:58:38 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
  protected:
	std::string type;

  public:
	WrongAnimal();
	WrongAnimal(const std::string &type);
	WrongAnimal(const WrongAnimal &copy);
	~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &copy);

	const std::string &getType() const;
	void setType(const std::string &type);

	virtual void makeSound() const;
};

#endif
