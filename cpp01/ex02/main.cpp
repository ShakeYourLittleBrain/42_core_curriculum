/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 00:04:32 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/30 03:13:47 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main( void )
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address of the str: " << &str << std::endl;
	std::cout << "A pointer to the *stringPTR: " << stringPTR << std::endl;
	std::cout << "A reference to the &stringREF: " << &stringREF << std::endl;

	std::cout << "str using the pointer: " << *stringPTR << std::endl;
	std::cout << "str using the reference: " << stringREF << std::endl;
	std::cout << "str using the variable: " << str << std::endl;
}
