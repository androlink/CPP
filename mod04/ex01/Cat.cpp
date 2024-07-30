/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:12:20 by gcros             #+#    #+#             */
/*   Updated: 2024/07/30 17:52:14 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():
	Animal("Cat"),
	brain(new Brain())
{
	std::cout << "[Cat]	Default constructor called" << std::endl;
}

Cat::Cat(const Cat &value):
	Animal(value),
	brain(new Brain())
{
	std::cout << "[Cat]	Copy constructor called" << std::endl;
	this->_type = value._type;
}

Cat::~Cat()
{
	std::cout << "[Cat]	Destructor called" << std::endl;
	delete this->brain;
}

Cat		&Cat::operator=(const Cat &value)
{
	this->_type = value._type;
	this->brain = new Brain(*(value.brain));
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (this->brain);
}
