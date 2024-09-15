/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:19:48 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/13 05:17:59 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

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

	/*
		we can define the exception classes inside the Bureaucrat class
		because they are only used in this class

		it is a personal preference to define the exception classes inside the class
		or create a new file for them.   I think i'm a lazy programmer :)
		in the later exercises we will define the exception classes in a new file
		so that multiple classes can use them till then be lazy

		keep in mind that the exception classes are derived from the std::exception class
		and what() function returns a const char* not (std::string). might be a small details
	*/
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

/*
	it is much better to define the operator overload outside the class
	if you don't want to use the friend keyword by the time you see this comment
	we will be allowed to use the c++11+ features so we can use friend keyword
	i pefer to start with the old way and then move to the new way when I'm comfortable
*/
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
