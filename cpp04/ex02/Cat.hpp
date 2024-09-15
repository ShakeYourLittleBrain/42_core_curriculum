/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 01:54:39 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/07 02:16:14 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
  private:
	Brain *_brain;

  public:
	Cat();
	Cat(const std::string &type);
	Cat(const Cat &copy);
	~Cat();

	Cat &operator=(const Cat &copy);

	void makeSound() const;
	const std::string &getType() const;
	void setType(const std::string &type);
};

#endif
