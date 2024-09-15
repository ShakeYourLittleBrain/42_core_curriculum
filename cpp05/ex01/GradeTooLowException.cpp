/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 05:42:15 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/13 07:16:39 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooLowException.hpp"

GradeTooLowException::GradeTooLowException() throw() {
	this->_msg = "Grade too low";
}

GradeTooLowException::GradeTooLowException(const std::string &msg) throw() : _msg(msg) {}

const char* GradeTooLowException::what() const throw() {
	return this->_msg.c_str();
}

GradeTooLowException::~GradeTooLowException() throw() {}
