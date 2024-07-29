/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:36:40 by gcros             #+#    #+#             */
/*   Updated: 2024/07/29 15:17:01 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include "string"
#include "iostream"

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &value);
		WrongAnimal(std::string type);
		~WrongAnimal();

		std::string	getType() const;
		void		setType(std::string v);
		WrongAnimal		&operator=(const WrongAnimal &value);
		void	makeSound() const;

	protected:
		std::string	_type;

};

#endif