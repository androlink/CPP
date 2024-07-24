/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:55:19 by gcros             #+#    #+#             */
/*   Updated: 2024/07/21 13:09:48 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int	orient(Point const p1, Point const p2, Point const point);
static int	iabs(int v);

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	int v;


	v = orient(a, b, point)
	+ orient(b, c, point)
	+ orient(c, a, point);
	if (iabs(v) != 3)
		return (false);
	return (true);
}

int	orient(Point const p1, Point const p2, Point const point)
{
	Point v1 = Point(p2.getX() - p1.getX(), p2.getY() - p1.getY());
	Point v2 = Point(point.getX() - p1.getX(), point.getY() - p1.getY());


	if (v1.getX() * v2.getY() - v1.getY() * v2.getX() == 0)
		return (0);
	if (v1.getX() * v2.getY() - v1.getY() * v2.getX() > 0)
		return (1);
	return (-1);
}

static int	iabs(int v)
{
	return (v < 0 ? -v : v);
}
