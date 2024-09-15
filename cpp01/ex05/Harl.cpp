/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:50:59 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/30 21:53:40 by skhastag         ###   ########.fr       */
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

/*
** This function will call the appropriate function based on the level passed as an argument.
** If the level is not found, it will print a custom error message.

********************************************************************************************
The goal of this exercise is to use pointers to member functions. This is not a
suggestion. Harl has to complain without using a forest of if/else if/else. It doesn’t think
twice!
********************************************************************************************
*/

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*actions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
		{
			(this->*actions[i])();
			return ;
		}
	}
	std::cout << "\033[31mCUSTOM ERROR: Unknown level '" << level << "' please see the usage\033[0m " << std::endl;
}
