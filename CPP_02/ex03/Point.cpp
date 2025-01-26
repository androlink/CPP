/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:55:14 by gcros             #+#    #+#             */
/*   Updated: 2024/10/17 16:52:15 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

	/*	constructor	*/

Point::Point():
x(0), y(0)
{
}

Point::Point(const Point &p):
x(p.getX()), y(p.getY())
{
}

Point::~Point()
{
}

Point::Point(const Fixed x, const Fixed y):
x(x), y(y)
{
}

Point::Point(const float x, const float y):
x(x), y(y)
{
}

	/*	utils	*/

Point &	Point::operator=(const Point &p1)
{
	(void) p1;
	return (*this);
}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}

std::ostream &	operator<<(std::ostream &os, const Point &p1)
{
	os << "[" << p1.getX() << ", " << p1.getY() << "]";
	return (os);
}
