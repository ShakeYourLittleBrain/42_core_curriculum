/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IsNotSignedException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:15:11 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/31 19:16:04 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_NOT_SIGNED_EXCEPTION_HPP
# define IS_NOT_SIGNED_EXCEPTION_HPP

# include <exception>
# include <iostream>

class IsNotSignedException : public std::exception
{
  private:
	std::string _msg;

  public:
	IsNotSignedException() throw();
	IsNotSignedException(const std::string &msg) throw();
	virtual ~IsNotSignedException() throw();
	virtual const char *what() const throw();
};

#endif
