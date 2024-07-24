/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:34:55 by gcros             #+#    #+#             */
/*   Updated: 2024/07/24 21:45:02 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

	/*	constructor	*/
ScavTrap::ScavTrap():
ClapTrap()
{
	std::cout << "[ScavTrap]	Default constructor called" << std::endl;
	hitPoint = 100;
	energy = 50;
	damage = 20;
}

ScavTrap::ScavTrap(std::string name):
ClapTrap(name)
{
	std::cout << "[ScavTrap]	name constructor called" << std::endl;
	hitPoint = 100;
	energy = 50;
	damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &value):
ClapTrap(value)
{
	std::cout << "[ScavTrap]	Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap]	Destructor called" << std::endl;
}

	/*	utils	*/
ScavTrap	&ScavTrap::operator=(const ScavTrap &value)
{
	this->damage = value.damage;
	this->name = value.name;
	this->hitPoint = value.hitPoint;
	this->energy = value.energy;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getEnergy() == 0 || this->getHitPoint() == 0)
	{
		std::cout << "ScavTrap "
		<< this->getName()
		<< " can't attack"
		<< std::endl;
		return ;
	}
	std::cout << "ScavTrap "
		<< this->getName()
		<< " attacks "
		<< target
		<< ", causing "
		<< this->getDamage()
		<< " points of damage!"
		<< std::endl;
	this->energy = this->energy <= 1 ? (0) : (this->energy - 1);
}

void	ScavTrap::guardGate()
{
	if (this->getHitPoint() == 0)
	{
		std::cout << "ScavTrap "
		<< this->getName()
		<< " as no life left"
		<< std::endl;
		return ;
	}
	std::cout << "ScavTrap "
	<< this->getName()
	<< " now guard the gate"
	<< std::endl;
}
