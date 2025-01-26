/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:17:31 by gcros             #+#    #+#             */
/*   Updated: 2024/07/21 12:13:16 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point p0;
	const Point p1 = Point(0.5, 0.5);
	Point p2 = Point(p1);
	const Point p3 = Point(10, 10);
	const Point p4 = Point(10, 0);
	const Point p5 = Point(4, 4);
	const Point p6 = Point(1, 2);
	const Point p7 = Point(2, 1);

	std::cout << "p0 : " << p0 << std::endl;
	std::cout << "p1 : " << p1 << std::endl;
	std::cout << "p2 : " << p2 << std::endl;
	std::cout << "p3 : " << p3 << std::endl;
	std::cout << "p4 : " << p4 << std::endl;
	std::cout << "p5 : " << p5 << std::endl;
	std::cout << "p6 : " << p6 << std::endl;
	std::cout << "p7 : " << p7 << std::endl;

	std::cout << "expected 0: " << bsp(p0, p3, p4, p5) << std::endl;
	std::cout << "expected 0: " << bsp(p0, p3, p4, p6) << std::endl;
	std::cout << "expected 1: " << bsp(p0, p3, p4, p7) << std::endl;
	std::cout << "expected 0: " << bsp(p0, p3, p4, p0) << std::endl;
	std::cout << "expected 0: " << bsp(p0, p4, p3, p0) << std::endl;
	std::cout << "expected 0: " << bsp(p0, p0, p1, p0) << std::endl;
	std::cout << "expected 0: " << bsp(p0, p0, p0, p0) << std::endl;
	
	return 0;
}

