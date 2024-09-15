/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 05:53:27 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/02 09:01:19 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


/*
To determine if a point is inside a triangle using area calculations, the approach is based on comparing areas. Here’s a concise explanation:

1.  Calculate the Area of the Triangle :
	Compute the area of the triangle formed by the three vertices using the determinant-based formula.

2.  Calculate Sub-Triangle Areas :
	For the point in question, compute the areas of the three triangles formed by including the point with each pair of the original triangle's vertices.

3.  Compare Areas :
	Check if the sum of the areas of the three sub-triangles equals the area of the original triangle. If the sum matches,
	the point lies inside or on the edge of the triangle; otherwise, it's outside.

This method works because if the point is within the triangle, the point's inclusion will exactly cover the triangle's total area when summing the areas of the sub-triangles.
	If the point is outside, the sum of the sub-triangle areas will be less than the area of the original triangle.


To determine if a point is inside a triangle using area calculation, follow these steps:

1.  Calculate the Area of the Triangle:

   For a triangle with vertices (x1, y1), (x2, y2), and (x3, y3), use the formula:

     Area ABC =  1 / 2 * abs( x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2))

2.  Calculate Areas of Sub-Triangles:

   Given a point (xp, yp), calculate the areas of the three triangles formed by including this point:

	 Area of Triangle PBC :

      Area_PBC =  1 / 2 * abs( xp * (y2 - y3) + x2 * (y3 - yp) + x3 * (yp - y2))


	 Area of Triangle PCA :

      Area_PCA =  1 / 2 * abs( xp * (y3 - y1) + x3 * (y1 - yp) + x1 * (yp - y3))


	 Area of Triangle PAB :

      Area_PAB =  1 / 2 * abs( xp * (y1 - y2) + x1 * (y2 - yp) + x2 * (yp - y1))

3.  Check if Point Is Inside the Triangle:

   To check if the point is inside the triangle, sum the areas of the three sub-triangles:

     Area_ABC =  Area_PBC +  Area_PCA +  Area_PAB

   If the sum of the sub-triangle areas equals the area of the original triangle, the point is inside or on the edge of the triangle. If not, the point is outside.

*/

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaABC = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / Fixed(2);
	Fixed areaPBC = (point.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - point.getY()) + c.getX() * (point.getY() - b.getY())) / Fixed(2);
	Fixed areaPCA = (point.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - point.getY()) + a.getX() * (point.getY() - c.getY())) / Fixed(2);
	Fixed areaPBA = (point.getX() * (b.getY() - a.getY()) + b.getX() * (a.getY() - point.getY()) + a.getX() * (point.getY() - b.getY())) / Fixed(2);

/*	std::cout << "areaABC: " << areaABC.abs() << std::endl;
	std::cout << "areaPBC: " << areaPBC.abs() << std::endl;
	std::cout << "areaPCA: " << areaPCA.abs() << std::endl;
	std::cout << "areaPBA: " << areaPBA.abs() << std::endl;
*/
	return (areaABC.abs() == areaPBC.abs() + areaPCA.abs() + areaPBA.abs());
}
