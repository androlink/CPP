/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:37:36 by gcros             #+#    #+#             */
/*   Updated: 2024/07/29 15:16:51 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "[WrongAnimal]	Default constructor called" << std::endl;
	_type = "missigno";
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "[WrongAnimal]	type constructor called" << std::endl;
	this->_type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &value)
{
	std::cout << "[WrongAnimal]	Copy constructor called" << std::endl;
	*this = value;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal]	Destructor called" << std::endl;
}

WrongAnimal		&WrongAnimal::operator=(const WrongAnimal &value)
{
	this->_type = value._type;
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::setType(std::string v)
{
	this->_type = v;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Mmh" << std::endl;
}
