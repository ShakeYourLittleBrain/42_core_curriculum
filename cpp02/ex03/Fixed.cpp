/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:10:01 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/02 07:27:55 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	//std::cout << "Default constructor called" << std::endl;
}

/*
The expression `value << _fractionalBits` performs a left bitwise shift on the integer `value` by `_fractionalBits` positions.
This operation is used to convert an integer to a fixed-point representation by adding fractional bits. Here’s a detailed breakdown of what it does and how it works:

1.  Left Bitwise Shift (`<<`) :
	The left shift operator `<<` shifts the bits of the integer `value` to the left by `_fractionalBits` positions.
	Each left shift by one position is equivalent to multiplying the number by 2. Thus, shifting left by `_fractionalBits` positions is equivalent to multiplying by \(2^{\_fractionalBits}\).

2.  Fixed-Point Representation :
	In fixed-point arithmetic, shifting a number left by `_fractionalBits` positions scales the number up by \(2^{\_fractionalBits}\),
	effectively converting an integer to a fixed-point number with `_fractionalBits` fractional bits.

	Example

Assume `value` is `3` and `_fractionalBits` is `8`:

1.  Binary Representation :
	If `value` is `3`, its binary representation is `11`.

2.  Left Shift by 8 :
	Shifting `11` left by `8` positions yields `1100000000` (which is `768` in decimal).

So, `value << _fractionalBits` results in `768`.

	Purpose

The primary purpose of this operation is to convert an integer into a fixed-point representation by adding fractional bits.
This is useful in scenarios where you need to perform fixed-point arithmetic. By left-shifting the integer `value`,
you create space for `_fractionalBits` fractional bits, allowing for precise representation of fractional values in subsequent operations.

	Context

In the context of fixed-point arithmetic, this operation might be used when initializing or assigning values to a fixed-point variable. For example:

- If you want to represent the integer `3` as a fixed-point number with 8 fractional bits, you would shift `3` left by `8` positions, resulting in `768`.
- This means the fixed-point representation of `3.0` (with 8 fractional bits) is `768`.

This allows for consistent and precise arithmetic operations on fixed-point numbers, leveraging the efficient integer arithmetic provided by most processors.
*/

Fixed::Fixed(const int value) : _value(value << _fractionalBits) {
	//std::cout << "Int constructor called" << std::endl;
}

/*
The line `_value = static_cast<int>(roundf(value * (1 << _fractionalBits)));` performs a series of operations to convert a floating-point number
`value` into a fixed-point representation. Here's a breakdown of what each part does:

1. value * (1 << _fractionalBits) :
	The `1 << _fractionalBits` expression shifts the number 1 left by `_fractionalBits` positions.
	This is equivalent to multiplying 1 by (2^{_fractionalBits}).
		Multiplying `value` by (2^{_fractionalBits}) scales the floating-point number `value` up by (2^{_fractionalBits}).
	This is a common step in fixed-point arithmetic to move the decimal point to the right by `_fractionalBits` places, effectively converting the fraction into an integer representation.

2. roundf(...) :
	The `roundf` function rounds the result of the multiplication to the nearest integer.
	This is necessary because fixed-point arithmetic needs an integer representation, and rounding ensures the closest approximation to the original floating-point value.

3. static_cast<int>(...) :
	The `static_cast<int>` converts the rounded floating-point number to an integer type. This is the final step in creating the fixed-point representation.

4. _value = ... :
	The result of the above operations is assigned to `_value`, which is presumably an integer variable designed to hold the fixed-point representation of `value`.

	Example

Assume `value` is `3.75` and `_fractionalBits` is `8`:
1. (1 << 8) results in (2^8 = 256).
2. `value * 960` gives (3.75 * 256 = 960.0).
3. `roundf(960.0)` results in `960`.
4. `static_cast<int>(960)` converts `960.0` (float) to `960` (int).

So, `_value` would be assigned `960`.

	Purpose

The purpose of this line is to store a floating-point number as a fixed-point number with a specific number of fractional bits,
	allowing for efficient storage and arithmetic operations while maintaining a certain precision.
*/

Fixed::Fixed(const float value) {
	_value = static_cast<int>(roundf(value * (1 << _fractionalBits)));
	//std::cout << "Float constructor called" << std::endl;
}

/*
The expression `static_cast<float>(_value) / (1 << _fractionalBits);` converts a fixed-point representation back to a floating-point representation.
	Here's a detailed breakdown of what each part does:

1. 	static_cast<float>(_value) :
	This converts the integer `_value`, which is in fixed-point representation, to a floating-point number.
	This is necessary to perform floating-point division in the next step.

2. 	1 << _fractionalBits :
	The `1 << _fractionalBits` expression shifts the number 1 left by `_fractionalBits` positions. This is equivalent to (2^{_fractionalBits}).
	If `_fractionalBits` is 8, then (1 << 8) is (2^8 = 256).

3.  Division :
	The expression `static_cast<float>(_value) / (1 << _fractionalBits)` divides the floating-point representation of `_value` by (2^{_fractionalBits}).
	This effectively scales the fixed-point number back down to its original floating-point value.

	Example

Assume `_value` is `960` and `_fractionalBits` is `8`:

1.	Convert to float : `static_cast<float>(_value)` converts `960` to `960.0`.
2.	Calculate (2^{_fractionalBits}) : `1 << 8` gives `256`.
3.	Perform division : `960.0 / 256` gives `3.75`.

So, the original floating-point value `3.75` is recovered from the fixed-point representation `960` with 8 fractional bits.

	Purpose

	This conversion is useful for interpreting or displaying fixed-point numbers in a human-readable floating-point format.
		Fixed-point arithmetic is often used for performance reasons or in hardware implementations, but at some point, you may need to convert
		the results back to floating-point for further processing or output. This expression performs that conversion accurately, maintaining the original value's precision.
*/

float Fixed::toFloat(void) const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

/*
	The expression `_value >> _fractionalBits` performs a right bitwise shift on the integer `_value` by `_fractionalBits` positions.
		This operation effectively converts a fixed-point representation back to an integer by discarding the fractional part.
		Here’s a breakdown of how this works and what it accomplishes:

1.  Right Bitwise Shift (`>>`) :
	The right shift operator `>>` shifts the bits of the integer `_value` to the right by `_fractionalBits` positions.
	Each right shift by one position is equivalent to dividing the number by 2 and discarding any remainder (i.e., truncating towards zero).

2.  Fixed-Point Representation :
	In a fixed-point representation with `_fractionalBits` fractional bits, the integer `_value` represents the original floating-point value scaled by \(2^{\_fractionalBits}\).
	For example, if `_fractionalBits` is 8, then `_value` is scaled by \(2^8 = 256\).

3.  Discarding the Fractional Part :
	By right-shifting `_value` by `_fractionalBits` positions, you effectively divide `_value` by \(2^{\_fractionalBits}\) and discard the fractional part.
	This converts the fixed-point number to an integer by truncating any fractional bits.

	Example

Assume `_value` is `960` and `_fractionalBits` is `8`:

1.  Binary Representation :
	If `_value` is `960`, its binary representation is `1111000000`.

2.  Right Shift by 8 :
	Shifting `1111000000` right by `8` positions yields `11` (which is `3` in decimal).

So, `_value >> _fractionalBits` results in `3`.

	Purpose

	The primary purpose of this operation is to convert a fixed-point number to an integer by removing the fractional part.
	This is useful in scenarios where you need an integer approximation of the fixed-point value. For instance, in some applications,
		you might need to display or use the integer part of a fixed-point number, and this operation provides an efficient way to achieve that.
*/

int Fixed::toInt(void) const {
	return _value >> _fractionalBits;
}

/********************************************************************************************/

Fixed::Fixed(const Fixed& other) {
	//std::cout << "Copy constructor called" << std::endl;
	_value = other._value;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	//std::cout << "Assignation operator called" << std::endl;
	if (this != &other) {
		_value = other._value;
	}
	return *this;
}

bool Fixed::operator>(const Fixed& other) const {
	return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
	return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
	return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
	return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
	return _value != other._value;
}

Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(toFloat() * other.toFloat());
}

/*
If you ever do a division by 0, it is acceptable that the program
crashes
but i will print an error message
and return a fixed point number with value 0
*/
Fixed Fixed::operator/(const Fixed& other) const {
	if (other.getRawBits() == 0) {
		std::cout << "Error: Division by zero" << std::endl;
		return Fixed(0);
	}
	int quotient = (_value << _fractionalBits) / other.getRawBits();
	Fixed result;
	result.setRawBits(quotient);
	return result;
}

Fixed& Fixed::operator++() {
	_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	_value++;
	return temp;
}


Fixed& Fixed::operator--() {
	_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	_value--;
	return temp;
}

Fixed Fixed::operator&&(const Fixed& other) const {
	return _value && other._value;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

int Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2) {
	return num1.getRawBits() < num2.getRawBits() ? num1 : num2;
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2) {
	return (num1.getRawBits() > num2.getRawBits()) ? num1 : num2;
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2) {
	return (num1.getRawBits() > num2.getRawBits()) ? num1 : num2;
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2) {
	return (num1.getRawBits() < num2.getRawBits()) ? num1 : num2;
}

Fixed Fixed::abs() const {
	return Fixed(_value < 0 ? -_value : _value);
}
