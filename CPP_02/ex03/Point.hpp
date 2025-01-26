/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:55:11 by gcros             #+#    #+#             */
/*   Updated: 2024/07/20 17:39:03 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _POINT_HPP_
#define _POINT_HPP_

#include <iostream>
#include "Fixed.hpp"

class Point
{
	public:
	/*	constructor	*/
		Point();
		Point(const Point &value);
		~Point();
		Point(const Fixed x, const Fixed y);
		Point(const float x, const float y);
		
	/*	utils	*/
		Fixed getX() const;
		Fixed getY() const;
		Point &	operator=(const Point &p1);

	private:

		Fixed const x;
		Fixed const y;

};

std::ostream &	operator<<(std::ostream &os, const Point &p1);

#endif // _POINT_HPP_