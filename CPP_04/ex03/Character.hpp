/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:05:35 by gcros             #+#    #+#             */
/*   Updated: 2024/11/07 21:29:37 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARCATER_HPP
# define CHARCATER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

# define MAX_MATERIA 4

class Character : virtual public ICharacter
{
	public:
/*                                     constructor                            */

		Character();
		Character(Character const &character);
		Character(std::string const &name);
		virtual ~Character();

/*                                     utils                                  */

		virtual std::string const	&getName() const;
		Character					&operator=(const Character &rp);

/*                                     func                                   */

		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

	private:
		std::string	_name;
		AMateria	*_materials[MAX_MATERIA];
};

#endif