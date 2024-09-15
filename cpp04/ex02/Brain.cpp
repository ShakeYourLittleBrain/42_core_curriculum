/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:33:08 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/07 00:48:52 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = copy._ideas[i];
	}
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& copy)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this == &copy)
		return *this;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = copy._ideas[i];
	}
	return *this;
}

void Brain::setIdea(const std::string& idea, int index)
{
	std::cout << "Brain idea setter called" << std::endl;
	_ideas[index] = idea;
}

const std::string& Brain::getIdea(int index) const
{
	std::cout << "Brain idea getter called" << std::endl;
	return _ideas[index];
}
