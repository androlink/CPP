/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:25:23 by gcros             #+#    #+#             */
/*   Updated: 2024/07/24 21:58:20 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	FragTrap s1;
	FragTrap s2 = FragTrap("Patric");
	FragTrap c1 = s1;
	FragTrap c2 = FragTrap("Michel");

	c1 = s2;

	std::cout << c1 << std::endl;
	std::cout << c2 << std::endl;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	c2.attack(s2.getName());
	s2.takeDamage(c2.getDamage());
	std::cout << s2 << std::endl;
	std::cout << c2 << std::endl;
	s2.attack(c2.getName());
	c2.takeDamage(s2.getDamage());
	std::cout << s2 << std::endl;
	std::cout << c2 << std::endl;

	s2.highFivesGuys();

}
