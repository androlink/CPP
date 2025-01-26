/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:05:58 by gcros             #+#    #+#             */
/*   Updated: 2024/11/07 21:29:04 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : virtual public AMateria
{
	public:
	
/*                                     constructor                            */

		Cure();
		Cure(const Cure &cure);
		virtual ~Cure();

/*                                     utils                                  */

		Cure	&operator=(const Cure &rp);
		virtual AMateria	*clone() const;

/*                                     func                                   */

		virtual void		use(ICharacter& target);
	protected:

};

#endif
