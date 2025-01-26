/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:46:43 by gcros             #+#    #+#             */
/*   Updated: 2024/07/30 17:15:36 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog &value);
		virtual ~Dog();

		Dog		&operator=(const Dog &value);
		virtual void	makeSound() const;
		Brain		*getBrain() const;

	private:
		Brain		*brain;

};


#endif