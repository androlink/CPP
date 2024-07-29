/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:37:36 by gcros             #+#    #+#             */
/*   Updated: 2024/07/29 15:17:08 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "[Animal]	Default constructor called" << std::endl;
	_type = "missigno";
}

Animal::Animal(std::string type)
{
	std::cout << "[Animal]	type constructor called" << std::endl;
	this->_type = type;
}

Animal::Animal(const Animal &value)
{
	std::cout << "[Animal]	Copy constructor called" << std::endl;
	*this = value;
}

Animal::~Animal()
{
	std::cout << "[Animal]	Destructor called" << std::endl;
}

Animal		&Animal::operator=(const Animal &value)
{
	this->_type = value._type;
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->_type);
}

void	Animal::setType(std::string v)
{
	this->_type = v;
}

void	Animal::makeSound() const
{
	std::cout << "Mmh" << std::endl;
}
