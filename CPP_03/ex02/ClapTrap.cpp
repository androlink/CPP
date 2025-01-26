/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:25:25 by gcros             #+#    #+#             */
/*   Updated: 2024/11/20 17:37:41 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

	/*	constructor	*/
ClapTrap::ClapTrap():
name("Jean?"), life(10), energy(10), damage(0)
{
	std::cout << "[ClapTrap]	Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name):
name(name), life(10), energy(10), damage(0)
{
	std::cout << "[ClapTrap]	name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &value)
{
	std::cout << "[ClapTrap]	Copy constructor called" << std::endl;
	*this = value;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap]	Destructor called" << std::endl;
}

	/*	utils	*/
ClapTrap	&ClapTrap::operator=(const ClapTrap &value)
{
	this->damage = value.damage;
	this->name = value.name;
	this->life = value.life;
	this->energy = value.energy;
	return (*this);
}

std::string	ClapTrap::getName() const
{
	return (this->name);
}

unsigned int	ClapTrap::getLife() const
{
	return (this->life);
}

unsigned int	ClapTrap::getEnergy() const
{
	return (this->energy);
}

unsigned int	ClapTrap::getDamage() const
{
	return (this->damage);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->getEnergy() == 0 || this->getLife() == 0)
	{
		std::cout << "ClapTrap "
		<< this->getName()
		<< " can't attack"
		<< std::endl;
		return ;
	}
	std::cout << "ClapTrap "
		<< this->getName()
		<< " attacks "
		<< target
		<< ", causing "
		<< this->getDamage()
		<< " points of damage!"
		<< std::endl;
	this->energy = this->energy <= 1 ? (0) : (this->energy - 1);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getLife() == 0)
	{
		std::cout << "ClapTrap "
		<< this->getName()
		<< " as no life left"
		<< std::endl;
		return ;
	}
	std::cout << "ClapTrap "
		<< this->getName()
		<< " take "
		<< amount
		<< " points of damage!"
		<< std::endl;
	this->life = this->life <= amount ? (0) : (this->life - amount);
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergy() == 0 || this->getLife() == 0)
	{
		std::cout << "ClapTrap "
		<< this->getName()
		<< " can't repair"
		<< std::endl;
		return ;
	}
	std::cout << "ClapTrap "
		<< this->getName()
		<< " repair "
		<< amount
		<< " points of damage!"
		<< std::endl;
	this->life += amount;
	this->energy = this->energy <= 1 ? (0) : (this->energy - 1);
}

std::ostream &operator<<(std::ostream &os, const ClapTrap &ct)
{
	os << "["
		<< "name: " << ct.getName()
		<< ", life: " << ct.getLife()
		<< ", energy: " << ct.getEnergy()
		<< ", damage: " << ct.getDamage()
		<< "]";
	return (os);
}
