/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:30:59 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/30 20:51:48 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;

	std::string input;
	while (std::cout << "usage: DEBUG, INFO, WARNING, ERROR or EXIT\n" << "Enter a level: ", std::getline(std::cin, input))
	{
		if (input == "EXIT")
			break ;
		harl.complain(input);
	}
	return (EXIT_SUCCESS);
}
