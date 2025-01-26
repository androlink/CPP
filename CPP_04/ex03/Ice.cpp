/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:08:54 by gcros             #+#    #+#             */
/*   Updated: 2024/11/07 21:37:29 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "iostream"
#include "ICharacter.hpp"

/*                                     constructor                            */

Ice::Ice():
	AMateria::AMateria("ice")
{
}

Ice::Ice(const Ice &ice):
	AMateria::AMateria(ice)
{
}

Ice::~Ice()
{
}

/*                                     utils                                  */

Ice	&Ice::operator=(const Ice &rp)
{
	(void) rp;
	return (*this);
}

AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	(void) target;
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<std::endl;
}
