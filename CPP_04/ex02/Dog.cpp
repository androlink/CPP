/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:12:20 by gcros             #+#    #+#             */
/*   Updated: 2024/07/30 17:52:11 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():
	Animal("Dog"),
	brain(new Brain())
{
	std::cout << "[Dog]	Default constructor called" << std::endl;
}

Dog::Dog(const Dog &value):
	Animal(value),
	brain(new Brain())
{
	std::cout << "[Dog]	Copy constructor called" << std::endl;
	this->_type = value._type;
}

Dog::~Dog()
{
	std::cout << "[Dog]	Destructor called" << std::endl;
	delete this->brain;
}

Dog		&Dog::operator=(const Dog &value)
{
	this->_type = value._type;
	this->brain = new Brain(*(value.brain));
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Ouaf" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (this->brain);
}
