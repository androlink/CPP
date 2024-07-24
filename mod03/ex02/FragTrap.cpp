/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:54:00 by gcros             #+#    #+#             */
/*   Updated: 2024/07/24 22:00:14 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

	/*	constructor	*/
FragTrap::FragTrap():
ClapTrap()
{
	std::cout << "[FragTrap]	Default constructor called" << std::endl;
	hitPoint = 100;
	energy = 100;
	damage = 30;
}

FragTrap::FragTrap(std::string name):
ClapTrap(name)
{
	std::cout << "[FragTrap]	name constructor called" << std::endl;
	hitPoint = 100;
	energy = 100;
	damage = 30;
}

FragTrap::FragTrap(const FragTrap &value):
ClapTrap(value)
{
	std::cout << "[FragTrap]	Copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap]	Destructor called" << std::endl;
}

	/*	utils	*/
FragTrap	&FragTrap::operator=(const FragTrap &value)
{
	this->damage = value.damage;
	this->name = value.name;
	this->hitPoint = value.hitPoint;
	this->energy = value.energy;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "[FragTrap]	hight five" << std::endl;

}
