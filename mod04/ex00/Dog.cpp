/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:12:20 by gcros             #+#    #+#             */
/*   Updated: 2024/07/29 13:32:11 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():
	Animal("Dog")
{
	std::cout << "[Dog]	Default constructor called" << std::endl;
}

Dog::Dog(const Dog &value):
Animal(value)
{
	std::cout << "[Dog]	Copy constructor called" << std::endl;
	*this = value;
}

Dog::~Dog()
{
	std::cout << "[Dog]	Destructor called" << std::endl;
}

Dog		&Dog::operator=(const Dog &value)
{
	this->_type = value._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Ouaf" << std::endl;
}