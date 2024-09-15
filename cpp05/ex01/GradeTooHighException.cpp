/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 05:42:39 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/13 07:16:26 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooHighException.hpp"

GradeTooHighException::GradeTooHighException() throw() {
	this->_msg = "Grade too high";
}

GradeTooHighException::GradeTooHighException(const std::string &msg) throw() : _msg(msg) {}

const char* GradeTooHighException::what() const throw() {
	return this->_msg.c_str();
}

GradeTooHighException::~GradeTooHighException() throw() {}
