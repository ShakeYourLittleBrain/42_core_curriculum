/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:05:33 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/13 00:58:08 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


/*****************************************************************************/
/*......https://rollbar.com/guides/cpp/how-to-handle-exceptions-in-cpp/......*/
/*......https://rollbar.com/blog/cpp-custom-exceptions/......................*/
/*......https://www.programiz.com/cpp-programming/exception-handling.........*/
/*****************************************************************************/


int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		try
		{
			Bureaucrat bureaucrat("John", 150);
			std::cout << bureaucrat << std::endl;
			std::cout << "Incrementing grade from: " << bureaucrat.getGrade() << std::endl;
			bureaucrat.incrementGrade();
			std::cout << bureaucrat << std::endl;
			std::cout << "Decrementing grade from: " << bureaucrat.getGrade() << std::endl;
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	else if (argc == 2)
	{
		try
		{
			Bureaucrat bureaucrat("John", std::stoi(argv[1]));
			std::cout << bureaucrat << std::endl;
			std::cout << "Incrementing grade from: " << bureaucrat.getGrade() << std::endl;
			bureaucrat.incrementGrade();
			std::cout << bureaucrat << std::endl;
			std::cout << "Decrementing grade from: " << bureaucrat.getGrade() << std::endl;
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;
			/****************************************************************************
				if the grade is 150 and we decrement it,
					it will throw an exception
				try to uncomment the line below to see the exception

			std::cout << "Decrementing grade from: " << bureaucrat.getGrade() << std::endl;
			bureaucrat.decrementGrade();
			****************************************************************************/
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	return (0);
}
