/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 06:31:58 by skhastag          #+#    #+#             */
/*   Updated: 2024/09/01 17:08:53 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
  std::cout << "---------------------------------------" << std::endl;
  std::cout << "---------ShrubberyCreationForm---------" << std::endl;
  std::cout << "---------------------------------------" << std::endl;
  try {
    Bureaucrat bureaucrat_sa("bur", 137);
    ShrubberyCreationForm FormA("target_file");
    //FormA.execute(bureaucrat_sa);
    std::cout << FormA << std::endl;
    FormA.beSigned(bureaucrat_sa);
    FormA.execute(bureaucrat_sa);
    std::cout << FormA << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "---------------------------------------" << std::endl;
  std::cout << "---------------------------------------" << std::endl;
  std::cout << "----------RobotomyRequestForm----------" << std::endl;
  std::cout << "---------------------------------------" << std::endl;
  try {
    Bureaucrat bureaucrat_rr("bur", 72);
    RobotomyRequestForm FormA("hellooo");
    std::cout << FormA << std::endl;
    FormA.beSigned(bureaucrat_rr);
    std::cout << FormA << std::endl;
    bureaucrat_rr.executeForm(FormA);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "---------------------------------------" << std::endl;
  std::cout << "---------------------------------------" << std::endl;
  std::cout << "--------PresidentialPardonForm---------" << std::endl;
  std::cout << "---------------------------------------" << std::endl;
  try {
    Bureaucrat bureaucrat_pp("bur", 25);
    // Bureaucrat bureaucrat_pp("bur", 4);
    PresidentialPardonForm FormA("hellooo");
    std::cout << FormA << std::endl;
    FormA.beSigned(bureaucrat_pp);
    std::cout << FormA << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "---------------------------------------" << std::endl;
}
