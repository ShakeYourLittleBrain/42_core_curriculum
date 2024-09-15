/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:26:26 by skhastag          #+#    #+#             */
/*   Updated: 2024/09/01 21:48:52 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request",
	72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other),
	_target(other._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

void RobotomyRequestForm::action() const
{
	std::cout << "Drilling noises..." << std::endl;
	if (rand() % 2 == 0)
	{
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << "Robotomy request failed for " << _target << "." << std::endl;
	}
}

AForm *RobotomyRequestForm::create(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}
