/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:58:30 by skhastag          #+#    #+#             */
/*   Updated: 2024/09/01 19:37:13 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation",
	145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation",
	145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other),
	_target(other._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

void ShrubberyCreationForm::action() const
{
	std::ofstream ofs(_target + "_shrubbery");
	if (ofs.is_open())
	{
		ofs << "      ccee88oo\n";
		ofs << "   C8O8O8Q8PoOb o8oo\n";
		ofs << "dOB69QO8PdUOpugoO9bD\n";
		ofs << "CgggbU8OU qOp qOdoUOdcb\n";
		ofs << "      6OuU  /p u gcoUodpP\n";
		ofs << "        \\\\//  /douUP\n";
		ofs << "          \\\\////\n";
		ofs << "            |||/\\\n";
		ofs << "            |||\\/\n";
		ofs << "            ||||||\n";
		ofs << "      .....//||||\\....\n";
		ofs.close();
		std::cout << "Shrubbery creation form has been executed successfully!" << std::endl;
	}
	else
	{
		throw std::runtime_error("Failed to open file for writing.");
	}
}

AForm *ShrubberyCreationForm::create(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}
