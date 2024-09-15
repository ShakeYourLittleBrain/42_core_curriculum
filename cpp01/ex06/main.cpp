/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:30:59 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/30 21:57:39 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*
*************************************************************************************************************
	** The files has the same creation time because I copied the content of the ex05 files to the ex06 files.
	and I modified the content of the files.
*************************************************************************************************************
*/

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "\033[31mUsage: " << argv[0] << " [DEBUG|INFO|WARNING|ERROR]\033[0m" << std::endl;
		return (EXIT_FAILURE);
	}
	Harl harl;
	harl.complain(argv[1]);
	return (EXIT_SUCCESS);
}
