/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:50:59 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/30 23:41:48 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "\033[96mDEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\033[0m" << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "\033[33mWARNING: I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.\033[0m" << std::endl;
}

void Harl::error(void)
{
	std::cout << "\033[31mERROR: This is unacceptable. I want to speak to the manager now.\033[0m" << std::endl;
}

int Harl::findIndex(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
			return (i);
	}
	return (4);
}

/*
** This function will call the appropriate function based on the level passed as an argument.
** If the level is not found, it will print a custom error message.

*************************************************************************************************************
The goal of this exercise is to use You must use, and maybe discover, the switch statement in this exercise.
if we don't use the break statement, the program will continue to execute the next case.
*************************************************************************************************************
*/

void Harl::complain(std::string level)
{
	int	enumLevel;

	void (Harl::*actions[])() = {&Harl::debug, &Harl::info, &Harl::warning,
		&Harl::error};
	enumLevel = findIndex(level);
	switch (enumLevel)
	{
	case 0:
		(this->*actions[0])();
	case 1:
		(this->*actions[1])();
	case 2:
		(this->*actions[2])();
	case 3:
		(this->*actions[3])();
		break;
	default:
		std::cerr << "\033[31mCUSTOM ERROR: Unknown level '" << level << "' please see the usage\033[0m\nUsage: ./HarlFilter [DEBUG|INFO|WARNING|ERROR]" << std::endl;
	}
}
