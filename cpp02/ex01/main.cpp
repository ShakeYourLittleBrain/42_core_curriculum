/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:08:34 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/02 20:12:13 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
A fixed-point number is a representation of a real number in which a fixed number of digits are reserved for the fractional part and the rest for the integer part.
Unlike floating-point numbers, which can represent a wide range of values with varying precision, fixed-point numbers have a fixed precision and scale.
This makes them particularly useful in systems where predictable precision and performance are crucial, such as embedded systems, digital signal processing, and financial applications.

Structure of Fixed-Point Numbers

	A fixed-point number can be represented as:

	Fixed-point number = Integer part + Fractional part


 Advantages and Disadvantages

**Advantages:**
- **Predictable Precision**: Fixed-point representation offers predictable precision, which is crucial for applications requiring exact numerical results.
- **Performance**: Fixed-point arithmetic is typically faster than floating-point arithmetic, especially on hardware without a floating-point unit (FPU).
- **Simplicity**: Easier to implement and understand compared to floating-point arithmetic.

**Disadvantages:**
- **Limited Range**: Fixed-point numbers have a limited range, which can be a significant limitation for applications requiring very large or very small values.
- **Scaling Issues**: Managing the scale (the fixed number of fractional bits) can be cumbersome, especially when performing arithmetic operations.
- **Precision Loss**: Fixed-point arithmetic can lead to precision loss, especially when dealing with very small fractions or very large integers.

### Use Cases

1. **Embedded Systems**: Many microcontrollers do not have hardware support for floating-point arithmetic, so fixed-point arithmetic is used instead.
2. **Digital Signal Processing (DSP)**: Fixed-point arithmetic is used in DSP for audio, video, and communications processing because of its predictable performance and precision.
3. **Financial Applications**: Fixed-point arithmetic is preferred in financial calculations to avoid precision issues associated with floating-point arithmetic.

### Conclusion

Fixed-point numbers offer a compromise between integer and floating-point representations,
providing a predictable precision and performance suitable for a variety of applications where the range of representable values is limited but precision and efficiency are critical.

*/

int	main(void)
{
	Fixed	a;

	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return (0);
}
