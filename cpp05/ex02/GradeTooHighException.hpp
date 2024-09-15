/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 05:40:12 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/14 13:34:02 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADE_TOO_HIGH_EXCEPTION_HPP
# define GRADE_TOO_HIGH_EXCEPTION_HPP

# include <exception>
# include <iostream>

class GradeTooHighException : public std::exception
{
  private:
	std::string _msg;

  public:
	GradeTooHighException() throw();
	GradeTooHighException(const std::string &msg) throw();
	virtual ~GradeTooHighException() throw();
	virtual const char *what() const throw();
};

#endif
