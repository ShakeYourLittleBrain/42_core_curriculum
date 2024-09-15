/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:19:48 by skhastag          #+#    #+#             */
/*   Updated: 2024/09/01 13:06:08 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "IsNotSignedException.hpp"
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
  private:
	std::string const _name;
	int _grade;

  public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &copy);

	const std::string &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &form) const;

	void executeForm(AForm const &form);
};

/*
	it is much better to define the operator overload outside the class
	if you don't want to use the friend keyword by the time you see this comment
	we will be allowed to use the c++11+ features so we can use friend keyword
	i pefer to start with the old way and then move to the new way when I'm comfortable
*/
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
