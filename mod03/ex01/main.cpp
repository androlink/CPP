/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:25:23 by gcros             #+#    #+#             */
/*   Updated: 2024/07/24 00:25:50 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ScavTrap	c1;
	ScavTrap	c2 = ScavTrap(c1);
	ScavTrap	c3;
	ScavTrap	c4 = ScavTrap("patrick");

	c3 = c2;
	std::cout << c1 << std::endl;
	std::cout << c2 << std::endl;
	std::cout << c3 << std::endl;
	std::cout << c4 << std::endl;

	c4.beRepaired(5);
	c4.takeDamage(1);
	c4.attack("michel");
	std::cout << c4 << std::endl;
	c4.takeDamage(15);
	std::cout << c4 << std::endl;
	c4.takeDamage(1);
	c4.beRepaired(5);
	c4.attack("michel");
	c4.guardGate();
}
