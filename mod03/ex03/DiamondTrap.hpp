/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:27:35 by gcros             #+#    #+#             */
/*   Updated: 2024/07/29 14:33:50 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DIAMONDTRAP_HPP_
#define _DIAMONDTRAP_HPP_

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{

	public:
	/*	constructor	*/
		DiamondTrap();
		DiamondTrap(std::string _name);
		DiamondTrap(const DiamondTrap &value);
		~DiamondTrap();

	/*	utils	*/
		DiamondTrap	&operator=(const DiamondTrap &value);
		void		whoAmI();

	private:
		std::string	name;
};

#endif // _DIAMONDTRAP_HPP_