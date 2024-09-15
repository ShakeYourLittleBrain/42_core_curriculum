/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 05:06:31 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/30 06:48:07 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "SedForWinners.hpp"

int	main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		std::cout << "Usage: ./replace filename s1 s2" << std::endl;
		std::cout << "make test" << std::endl;
		return (1);
	}

	SedForWinners	sed(argv[1]);

	sed.readfileToContent();
	sed.replaceStringInContent(argv[2], argv[3]);
	sed.writeContentToFile();
	return (0);
}

