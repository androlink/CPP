/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:17:45 by gcros             #+#    #+#             */
/*   Updated: 2024/10/24 15:01:23 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::frac = 8;

/*                                     constructor                            */

Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const Fixed &f)
{
	this->_value = f.getRawBits();
}

Fixed::Fixed(const int value)
{
	this->_value = value << Fixed::frac;
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (float)(1 << Fixed::frac));
}

Fixed::~Fixed()
{
}

/*                                     utils                                  */

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int raw_value)
{
	_value = raw_value;
}

Fixed &	Fixed::operator=(const Fixed &p1)
{
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

Fixed &	Fixed::min(Fixed &p1, Fixed &p2)
{
	return (p1.getRawBits() < p2.getRawBits() ? p1 : p2);
}

const Fixed &	Fixed::min(const Fixed &p1, const Fixed &p2)
{
	return (p1.getRawBits() < p2.getRawBits() ? p1 : p2);
}

Fixed &	Fixed::max(Fixed &p1, Fixed &p2)
{
	return (p1.getRawBits() > p2.getRawBits() ? p1 : p2);
}

const Fixed &	Fixed::max(const Fixed &p1, const Fixed &p2)
{
	return (p1.getRawBits() > p2.getRawBits() ? p1 : p2);
}

/*                                     cond                                   */

bool	Fixed::operator<(const Fixed &p1) const
{
	return (this->getRawBits() < p1.getRawBits());
}

bool	Fixed::operator<=(const Fixed &p1) const
{
	return (this->getRawBits() <= p1.getRawBits());
}

bool	Fixed::operator>=(const Fixed &p1) const
{
	return (this->getRawBits() >= p1.getRawBits());
}

bool	Fixed::operator>(const Fixed &p1) const
{
	return (this->getRawBits() > p1.getRawBits());
}

bool	Fixed::operator==(const Fixed &p1) const
{
	return (this->getRawBits() == p1.getRawBits());
}

bool	Fixed::operator!=(const Fixed &p1) const
{
	return (this->getRawBits() != p1.getRawBits());
}

/*                                     arith                                  */

Fixed	Fixed::operator+(const Fixed &p1) const
{
	Fixed tmp;

	tmp.setRawBits(this->_value + p1._value);
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed &p1) const
{
	Fixed tmp;

	tmp.setRawBits(this->_value - p1._value);
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed &p1) const
{
	long	l0;
	long	l1;
	
	l0 = this->_value;
	l1 =  p1._value;
	return (Fixed((l0 * l1) / (float)((1 << Fixed::frac) * (1 << Fixed::frac))));
}

Fixed	Fixed::operator/(const Fixed &p1) const
{
	return (Fixed((this->_value / (float)p1._value)));
}

/*                                     increment / decrement                  */

Fixed 	Fixed::operator++(int v)
{
	(void) v;
	Fixed f = *this;
	this->setRawBits( this->getRawBits() + 1);
	return (f);
}

Fixed &	Fixed::operator++()
{
	this->setRawBits( this->getRawBits() + 1);
	return (*this);
}

Fixed 	Fixed::operator--(int v)
{
	(void) v;
	Fixed f = *this;
	this->setRawBits( this->getRawBits() - 1);
	return (f);
}

Fixed &	Fixed::operator--()
{
	this->setRawBits( this->getRawBits() - 1);
	return (*this);
}
