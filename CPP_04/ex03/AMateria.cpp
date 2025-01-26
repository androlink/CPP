/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:20:50 by gcros             #+#    #+#             */
/*   Updated: 2024/11/07 17:57:01 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "iostream"

/*                                     constructor                            */

AMateria::AMateria():
	_type("NaN")
{
}

AMateria::AMateria(const AMateria &amateria)
{
	this->_type = amateria._type;
}

AMateria::AMateria(std::string const & type):
	_type(type)
{
}

AMateria::~AMateria()
{
}

/*                                     utils                                  */

AMateria	&AMateria::operator=(const AMateria &rp)
{
	(void) rp;
	return (*this);
}

std::string const	&AMateria::getType() const
{
	return (this->_type);
}

/*                                     func                                   */

void	AMateria::use(ICharacter& target)
{
	(void) target;
	std::cout << "hello there !" << std::endl;
}
