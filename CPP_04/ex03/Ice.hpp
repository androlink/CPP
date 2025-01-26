/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:05:58 by gcros             #+#    #+#             */
/*   Updated: 2024/11/07 17:29:30 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : virtual public AMateria
{
	public:
	
/*                                     constructor                            */

		Ice();
		Ice(const Ice &ice);
		virtual ~Ice();

/*                                     utils                                  */

		Ice	&operator=(const Ice &rp);
		virtual AMateria	*clone() const;

/*                                     func                                   */

		virtual void		use(ICharacter& target);
	protected:

};

#endif
