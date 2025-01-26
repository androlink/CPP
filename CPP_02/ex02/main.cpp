/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:17:31 by gcros             #+#    #+#             */
/*   Updated: 2024/10/17 15:44:36 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

void	basic();
void	cond();
void	arith();

int main( void ) {
	Fixed f0;
	Fixed f1 = Fixed(9);
	Fixed f2 = Fixed(f1);
	Fixed f3 = f2 / 2;
	Fixed f4 = Fixed(10.1f);

	std::cout << "expected 0: " << f0 << std::endl;
	std::cout << "expected 9: " << f1 << std::endl;
	std::cout << "expected 9: " << f2 << std::endl;
	std::cout << "expected " << Fixed(4.5f) << ": " << f3 << std::endl;
	std::cout << "expected " << Fixed(10.1f) << ": " << f4 << std::endl;
	std::cout << "expected " << f4 << ": " << Fixed::max(f4, f3) << std::endl;
	std::cout << "expected " << ++Fixed(10.1f) << ": " << ++f4 << std::endl;
	std::cout << "expected " << ++Fixed(10.1f) + f3 << ": " << f4 + f3 << std::endl;
	std::cout << "expected " << (++Fixed(10.1f)).toInt() << ": " << f4.toInt() << std::endl;
	std::cout << "expected " << (++Fixed(10.1f) * -1).toInt() << ": " << (f4 * -1).toInt() << std::endl;
	std::cout << "expected " << (++Fixed(10.1f)) * -1 << ": " << f4 * -1 << std::endl;
	
	basic();
	cond();
	arith();
	return 0;
}

void	arith()
{
	std::cout << "	arith test" << std::endl;

	Fixed a(0);
	Fixed b(-10.10f);
	Fixed c(+10.10f);

	std::cout << (a + c) <<  " : +10.10" << std::endl;
	std::cout << (a - c) <<  " : -10.10" << std::endl;
	std::cout << (a * c) <<  " : 0" << std::endl;
	std::cout << (a / c) <<  " : 0" << std::endl;

	std::cout << (a + b) <<  " : -10.10" << std::endl;
	std::cout << (a - b) <<  " : +10.10" << std::endl;
	std::cout << (a * b) <<  " : 0" << std::endl;
	std::cout << (a / b) <<  " : 0" << std::endl;

	std::cout << (c + b) <<  " : 0" << std::endl;
	std::cout << (c - b) <<  " : 20.20" << std::endl;
	std::cout << (c * b) <<  " : -102,01" << std::endl;
	std::cout << (c / b) <<  " : -1" << std::endl;
}

void	cond()
{
	std::cout << "	cond test" << std::endl;

	Fixed a(0);
	Fixed b(-1);
	Fixed c(+1);

	std::cout << (a < b) <<  " : 0" << std::endl;
	std::cout << (a > b) <<  " : 1" << std::endl;
	std::cout << (a == b) <<  " : 0" << std::endl;
	std::cout << (a < a) <<  " : 0" << std::endl;
	std::cout << (a <= a) <<  " : 1" << std::endl;
	std::cout << (a != a) <<  " : 0" << std::endl;
	std::cout << (a > c) <<  " : 0" << std::endl;
	
}

void	basic()
{
	std::cout << "	basic test" << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}
