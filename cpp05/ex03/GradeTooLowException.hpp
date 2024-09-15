/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 05:39:15 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/14 13:30:19 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADE_TOO_LOW_EXCEPTION_HPP
# define GRADE_TOO_LOW_EXCEPTION_HPP

# include <exception>
# include <iostream>

class GradeTooLowException : public std::exception
{
  private:
	std::string _msg;

  public:
	GradeTooLowException() throw();
	GradeTooLowException(const std::string &msg) throw();
	virtual ~GradeTooLowException() throw();
	virtual const char *what() const throw();
};

#endif
