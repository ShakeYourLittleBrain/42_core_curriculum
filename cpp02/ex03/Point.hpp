/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 05:08:21 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/02 17:55:58 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
  private:
	Fixed x;
	Fixed y;

  public:
	Point();
	Point(const Point &copy);
	Point(const float, const float y);
	~Point();

	Point &operator=(const Point &copy);

	Fixed getX() const;
	Fixed getY() const;
};

#endif
