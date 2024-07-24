/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:17:53 by gcros             #+#    #+#             */
/*   Updated: 2024/07/21 22:58:48 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
# define _FIXED_HPP_

#include <iostream>

class Fixed
{
	public :
	/*	constructor	*/
		Fixed();
		Fixed(const Fixed &value);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();

	/*	utils	*/
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed &	operator=(const Fixed &p1);

	private :

		int					_value;
		const static int	frac;
};

std::ostream &	operator<<(std::ostream &os, const Fixed &p1);


#endif