/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IsNotSignedException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:16:35 by skhastag          #+#    #+#             */
/*   Updated: 2024/09/01 11:35:14 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IsNotSignedException.hpp"

IsNotSignedException::IsNotSignedException() throw() {
	this->_msg = "Error: Value is not signed";
}

IsNotSignedException::IsNotSignedException(const std::string &msg) throw() : _msg(msg) {}

const char* IsNotSignedException::what() const throw() {
	return this->_msg.c_str();
}

IsNotSignedException::~IsNotSignedException() throw() {}
