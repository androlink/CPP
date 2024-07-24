/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:54:17 by gcros             #+#    #+#             */
/*   Updated: 2024/07/24 21:56:48 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAGTRAP_HPP_
#define _FRAGTRAP_HPP_

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{

	public:
	/*	constructor	*/
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &value);
		~FragTrap();

	/*	utils	*/
		FragTrap	&operator=(const FragTrap &value);
		void		highFivesGuys(void);

	private:

};

#endif // _FRAGTRAP_HPP_
