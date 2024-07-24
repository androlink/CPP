/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:55:14 by gcros             #+#    #+#             */
/*   Updated: 2024/07/21 01:42:00 by gcros            ###   ########.fr       */
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
	(Fixed)this->x = p1.x;
	(Fixed)this->y = p1.y;
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
