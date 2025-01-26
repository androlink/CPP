/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:57:32 by gcros             #+#    #+#             */
/*   Updated: 2024/11/07 21:03:12 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARCATER_HPP
# define ICHARCATER_HPP

# include <string>
# include "AMateria.hpp"

class ICharacter
{
	public:

/*                                     constructor                            */

		virtual ~ICharacter(){}

/*                                     utils                                  */

		virtual std::string const & getName() const = 0;

/*                                     func                                   */

		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif