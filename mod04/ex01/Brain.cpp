/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:22:48 by gcros             #+#    #+#             */
/*   Updated: 2024/07/29 18:12:25 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain]	Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
}

Brain::Brain(const Brain &brain)
{
	std::cout << "[Brain]	Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
}

Brain::~Brain()
{
	std::cout << "[Brain]	Destructor called" << std::endl;
}

void	Brain::setIdeaAt(std::string newIdea, int index)
{
	this->ideas[index] = newIdea;
}

std::string	Brain::getIdeaAt(int index) const
{
	return (this->ideas[index]);
}

Brain &Brain::operator=(const Brain &rp)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rp.ideas[i];
	return (*this);
}
