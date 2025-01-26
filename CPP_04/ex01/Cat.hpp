/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:46:17 by gcros             #+#    #+#             */
/*   Updated: 2024/07/30 17:15:33 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat &value);
		virtual ~Cat();

		Cat		&operator=(const Cat &value);
		virtual void	makeSound() const;
		Brain		*getBrain() const;

	private:
		Brain		*brain;

};


#endif