/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:14:04 by skhastag          #+#    #+#             */
/*   Updated: 2024/09/01 21:47:14 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
		(void)other;
	}
	return *this;
}

AForm *Intern::makeForm(const std::string &formName,
	const std::string &target) const
{
	const std::string formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	/*
		* The formCreators array is an array of function pointers. Each function pointer points to a function that takes a string as an argument and returns a pointer to an AForm object.
		* The formCreators array is initialized with the addresses of the create functions of the three form classes.
		* The functions should be static,
			so that they can be called without an object of the class.
		* This is because the create function is called by the Intern class,
			which does not have an object of the specific form class.
		* And AForm is the base class of all form classes. and it is just a abstract class.
		* we are using AForm* to hold the address of the different object of the derived class.
		* for this reason we have to use static function.
	*/

	AForm *(*formCreators[])(const std::string &) = {&PresidentialPardonForm::create,
		&RobotomyRequestForm::create, &ShrubberyCreationForm::create};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return (formCreators[i](target));
		}
	}
	/*
	* We could also use switch case here.
	* But we are using this method which is my favourite.
	*/

	std::cout << "Intern cannot create " << formName << " form" << std::endl;
	return (NULL);
}
