/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:20:17 by gcros             #+#    #+#             */
/*   Updated: 2024/11/07 17:29:12 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "string"

class ICharacter;

class AMateria
{
	public:

/*                                     constructor                            */

		AMateria();
		AMateria(const AMateria &amateria);
		AMateria(std::string const & type);
		virtual ~AMateria();

/*                                     utils                                  */

		AMateria			&operator=(const AMateria &rp);
		std::string const	&getType() const;
		virtual AMateria	*clone() const = 0;

/*                                     func                                   */

		virtual void		use(ICharacter& target);

	protected:

		std::string			_type;
};

#endif
