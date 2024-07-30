/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:36:40 by gcros             #+#    #+#             */
/*   Updated: 2024/07/30 18:10:47 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "string"
#include "iostream"

class Animal
{
	public:

		virtual ~Animal();
		Animal(const Animal &value);
		Animal();
		Animal(std::string type);

		std::string	getType() const;
		void		setType(std::string v);
		Animal		&operator=(const Animal &value);
		virtual void	makeSound() const = 0;

	protected:
		std::string	_type;

};

#endif