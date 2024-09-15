/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 06:31:58 by skhastag          #+#    #+#             */
/*   Updated: 2024/09/02 16:28:30 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void)
{
	Intern	someRandomIntern;
	AForm	*rrf;

	try
	{
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "----------RobotomyRequestForm----------" << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << rrf->getName() << std::endl;
		rrf->action();
		delete	rrf;
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "---------ShrubberyCreationForm---------" << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout << rrf->getName() << std::endl;
		rrf->action();
		delete	rrf;
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "--------PresidentialPardonForm---------" << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << rrf->getName() << std::endl;
		rrf->action();
		delete	rrf;
		std::cout << "---------------------------------------" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
