/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:08:53 by gcros             #+#    #+#             */
/*   Updated: 2024/11/13 15:11:38 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*                                     constructor                            */

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		_materials[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & rp)
{
	for (size_t i = 0; i < 4; i++)
		this->_materials[i] = rp._materials[i];
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		delete this->_materials[i];
}

/*                                     func                                   */

void MateriaSource::learnMateria(AMateria *materia)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_materials[i] == NULL)
		{
			this->_materials[i] = materia;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materials[i] == NULL)
			continue ;
		if (this->_materials[i]->getType() == type)
			return (this->_materials[i]->clone());
	}
	return (NULL);
}
