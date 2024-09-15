/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 06:31:58 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/13 07:19:54 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat bureaucrat("John", 150);
		std::cout << bureaucrat << std::endl;

		Form form("Form1", 100, 50);
		std::cout << form << std::endl;

		bureaucrat.signForm(form);
		std::cout << form << std::endl;

		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;

		bureaucrat.signForm(form);
		std::cout << form << std::endl;

		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;

		form.beSigned(bureaucrat);

	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
