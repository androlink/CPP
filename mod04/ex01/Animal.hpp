/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:36:40 by gcros             #+#    #+#             */
/*   Updated: 2024/07/29 16:22:18 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "string"
#include "iostream"
#include "Brain.hpp"

class Animal
{
	public:
		Animal();
		Animal(const Animal &value);
		Animal(std::string type);
		virtual ~Animal();

		std::string	getType() const;
		void		setType(std::string v);
		Brain		*getBrain() const;
		Animal		&operator=(const Animal &value);
		virtual void	makeSound() const;

	protected:
		std::string	_type;
		Brain		*brain;

};

#endif