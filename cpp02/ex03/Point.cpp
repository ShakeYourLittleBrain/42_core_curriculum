/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 05:10:57 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/02 17:56:54 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0){}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::Point(const float xValue, const float yValue) : x(xValue), y(yValue) {}

Point::~Point() {}

Point& Point::operator=(const Point& other)
{
	if (this == &other)
		return *this;
	x = other.x;
	y = other.y;
	return *this;
}

Fixed Point::getX() const { return x; }

Fixed Point::getY() const { return y; }

