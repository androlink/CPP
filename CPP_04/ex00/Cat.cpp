/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:12:20 by gcros             #+#    #+#             */
/*   Updated: 2024/07/29 13:32:03 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():
	Animal("Cat")
{
	std::cout << "[Cat]	Default constructor called" << std::endl;
}

Cat::Cat(const Cat &value):
Animal(value)
{
	std::cout << "[Cat]	Copy constructor called" << std::endl;
	*this = value;
}

Cat::~Cat()
{
	std::cout << "[Cat]	Destructor called" << std::endl;
}

Cat		&Cat::operator=(const Cat &value)
{
	this->_type = value._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}
