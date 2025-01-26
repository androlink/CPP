/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:17:53 by gcros             #+#    #+#             */
/*   Updated: 2024/10/17 14:06:59 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
# define _FIXED_HPP_

class Fixed
{
	public :
		Fixed();
		Fixed(const Fixed &value);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed &	operator=(const Fixed &p1);

	private :

		int				_value;
		const static	int	frac;
};



#endif