/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:08:54 by gcros             #+#    #+#             */
/*   Updated: 2024/11/07 21:37:03 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "iostream"
#include "ICharacter.hpp"
/*                                     constructor                            */

Cure::Cure():
	AMateria::AMateria("cure")
{
}

Cure::Cure(const Cure &cure):
	AMateria::AMateria(cure)
{
}

Cure::~Cure()
{
}

/*                                     utils                                  */

Cure	&Cure::operator=(const Cure &rp)
{
	(void) rp;
	return (*this);
}

AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	(void) target;
	std::cout << "* heals " << target.getName() << "'s wounds *" <<std::endl;
}
