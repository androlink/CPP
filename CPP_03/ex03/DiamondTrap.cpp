/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:27:33 by gcros             #+#    #+#             */
/*   Updated: 2024/11/20 18:09:24 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

	/*	constructor	*/
DiamondTrap::DiamondTrap():
ScavTrap(), FragTrap()
{
	std::cout << "[DiamondTrap]	Default constructor called" << std::endl;
	this->name = ClapTrap::name;
	ClapTrap::name = ClapTrap::name + "_clap_name";
	life = 100;
	energy = 100;
	damage = 30;
}

DiamondTrap::DiamondTrap(std::string _name):
ScavTrap(_name), FragTrap(_name)
{
	std::cout << "[DiamondTrap]	name constructor called" << std::endl;
	this->name = ClapTrap::name;
	ClapTrap::name = ClapTrap::name + "_clap_name";
	life = 100;
	energy = 50;
	damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &value):
ClapTrap(value), ScavTrap(value), FragTrap(value)
{
	std::cout << "[DiamondTrap]	Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap]	Destructor called" << std::endl;
}

	/*	utils	*/
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &value)
{
	this->damage = value.damage;
	this->name = value.name;
	this->life = value.life;
	this->energy = value.energy;
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "[DiamondTrap]	I am :" << this->name << ", as: " << this->ClapTrap::getName() << std::endl;
}
