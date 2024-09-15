/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:08:34 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/02 18:40:37 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
# Convexity of a Triangle

	Convexity of a Triangle

A triangle, by definition, is a polygon with three edges and three vertices. It is always a convex shape because for any two points inside the triangle,
	the line segment connecting those two points lies entirely within the triangle. This is true for all types of triangles: equilateral, isosceles, and scalene.

	Visual Representation

Consider a triangle with vertices ( A ), ( B ), and ( C ):

```
   A
  / \
 /   \
B-----C
```

If you pick any two points within this triangle, the line segment connecting them will always stay inside the boundaries of the triangle.

	Why a Triangle is Convex

1.  Interior Angles :
	The sum of the interior angles of a triangle is always 180 degrees.
	Since each angle is less than 180 degrees, the shape does not bend inwards, which characterizes convexity.

2.  Line Segments :
	Any line segment drawn between two points within the triangle remains within the triangle. This is a key property of convex regions.

	Practical Implications

In computational geometry and applications such as BSP, using triangles (or more generally, convex polygons) simplifies many operations:

- **Collision Detection**: It's straightforward to check if a point is inside a triangle or if two triangles intersect.
- **Rendering**: Graphics engines often break down complex shapes into triangles for rendering, as triangles are always convex and thus easier to handle.
- **Tessellation**: Dividing a complex shape into triangles ensures that the resulting pieces are convex, making geometric algorithms more efficient.

	Comparison with Non-Convex Shapes

For contrast, consider an L-shaped polygon, which is non-convex:

```
+---+
|   |
|   +----+
|        |
+--------+
```

If you draw a line segment between a point in the top left part and a point in the bottom right part, it will pass outside the L-shaped region, demonstrating its non-convexity.

	Summary

- A triangle is always a convex region.
- Convex regions, like triangles, have properties that make them computationally simpler to manage.
- Triangles are fundamental in computational geometry, graphics, and game development due to their simplicity and the fact that they are always convex.
*/

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	std::cout << " Point(0, 0) , Point(0, 4) , Point(4, 0) " << std::endl;
	std::cout << " Point(2, 2) " << (bsp(Point(0, 0), Point(0, 4), Point(4, 0), Point(2, 2)) ? "is " : "not ") << "inside the triangle" << std::endl << std::endl;

	std::cout << " Point(1, 1) , Point(2, 1) , Point(1, 2) " << std::endl;
	std::cout << " Point(1, 1) " << (bsp(Point(0, 0), Point(0, 4), Point(4, 0), Point(1.0f, 1.0f)) ? "is " : "not ") << "inside the triangle" << std::endl << std::endl;

	std::cout << " Point(3, 3) , Point(2, 3) , Point(1, 2) " << std::endl;
	std::cout << " Point(3, 3) " << (bsp(Point(0, 0), Point(0, 4), Point(4, 0), Point(3, 3)) ? "is " : "not ") << "inside the triangle" << std::endl << std::endl;

	std::cout << " Point(1, 1) , Point(2, 1) , Point(1, 2) " << std::endl;
	std::cout << " Point(2, 3) " << (bsp(Point(1, 1), Point(2, 1), Point(1, 2), Point(8.0f, 3.0f)) ? "is " : "not ") << "inside the triangle" << std::endl << std::endl;

	return (0);
}
