/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:25:23 by gcros             #+#    #+#             */
/*   Updated: 2024/07/21 18:43:24 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	c1;
	ClapTrap	c2 = ClapTrap(c1);
	ClapTrap	c3;
	ClapTrap	c4 = ClapTrap("patrick");

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
}
