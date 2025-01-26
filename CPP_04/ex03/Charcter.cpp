/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Charcter.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:09:29 by gcros             #+#    #+#             */
/*   Updated: 2024/11/13 15:31:52 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*                                     constructor                            */

Character::Character():
_name("NaN")
{
	for (size_t i = 0; i < MAX_MATERIA; i++)
		this->_materials[i] = NULL;
}

Character::Character(Character const &rp)
{
	this->_name = rp.getName();
	for (size_t i = 0; i < MAX_MATERIA; i++)
	{
		if (rp._materials[i] == NULL)
			this->_materials[i] = NULL;
		else
			this->_materials[i] = rp._materials[i]->clone();
	}
}

Character::Character(std::string const &name):
_name(name)
{
	for (size_t i = 0; i < MAX_MATERIA; i++)
		 this->_materials[i] = NULL;
}

Character::~Character()
{
	for (size_t i = 0; i < MAX_MATERIA; i++)
		delete this->_materials[i];
}

/*                                     utils                                  */

std::string const &Character::getName() const
{
	return (this->_name);
}

Character	&Character::operator=(const Character &rp)
{
	this->_name = rp.getName();
	for (size_t i = 0; i < MAX_MATERIA; i++)
	{
		this->_materials[i] = rp._materials[i]->clone();
	}
	return (*this);
}

/*                                     func                                   */

void Character::equip(AMateria* m)
{
	for (size_t i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_materials[i] == NULL)
		{
			this->_materials[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_MATERIA)
		return ;
	this->_materials[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_MATERIA)
		return ;
	if (this->_materials[idx] == NULL)
		return ;
	this->_materials[idx]->use(target);
}
