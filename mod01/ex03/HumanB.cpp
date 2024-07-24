/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:45:29 by gcros             #+#    #+#             */
/*   Updated: 2024/07/13 17:56:18 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(void):
	weapon(NULL)
{
}

HumanB::HumanB(std::string name):
	name(name)
{
}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = new Weapon(weapon);
}

HumanB::~HumanB(void)
{
	delete this->weapon;
}
