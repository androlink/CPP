/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:33:36 by gcros             #+#    #+#             */
/*   Updated: 2024/06/13 15:18:04 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
}

Weapon::~Weapon(void)
{
}

Weapon::Weapon(std::string type):
	type(type)
{
}

const std::string	&Weapon::getType(void)
{
	return(this->type);
}

void	Weapon::setType(std::string type){
	this->type = type;
}
