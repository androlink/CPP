/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:17:45 by gcros             #+#    #+#             */
/*   Updated: 2024/07/14 19:47:25 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::frac = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = value;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << Fixed::frac;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (float)(1 << Fixed::frac));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int raw_value)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw_value;
}

Fixed &	Fixed::operator=(const Fixed &p1)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = p1.getRawBits();
	return (*this);
}

float	Fixed::toFloat(void) const
{
	return (this->_value / (float)(1 << Fixed::frac));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> Fixed::frac);
}

std::ostream &	operator<<(std::ostream &os, const Fixed &p1)
{
	os << p1.toFloat();
	return (os);
}
