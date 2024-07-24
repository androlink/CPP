/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:17:31 by gcros             #+#    #+#             */
/*   Updated: 2024/07/21 15:19:19 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

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
	
	return 0;
}

