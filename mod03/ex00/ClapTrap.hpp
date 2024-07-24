/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:25:20 by gcros             #+#    #+#             */
/*   Updated: 2024/07/21 18:09:17 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_HPP_
#define _CLAPTRAP_HPP_

#include <string>
#include <iostream>

class	ClapTrap
{
	public:
	/*	constructor	*/
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap & value);
		~ClapTrap();

	/*	utils	*/
		ClapTrap		&operator=(const ClapTrap &value);
		std::string		getName() const;
		unsigned int	getHitPoint() const;
		unsigned int	getEnergy() const;
		unsigned int	getDamage() const;

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		std::string		name;
		unsigned int	hitPoint;
		unsigned int	energy;
		unsigned int	damage;
	
};

std::ostream &operator<<(std::ostream &os, const ClapTrap &ct);

#endif // _CLAPTRAP_HPP_