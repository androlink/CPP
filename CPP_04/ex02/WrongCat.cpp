/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:12:20 by gcros             #+#    #+#             */
/*   Updated: 2024/07/29 13:38:29 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat():
	WrongAnimal("WrongCat")
{
	std::cout << "[WrongCat]	Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &value):
WrongAnimal(value)
{
	std::cout << "[WrongCat]	Copy constructor called" << std::endl;
	*this = value;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat]	Destructor called" << std::endl;
}

WrongCat		&WrongCat::operator=(const WrongCat &value)
{
	this->_type = value._type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}
