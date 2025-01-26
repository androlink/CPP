/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:05:04 by gcros             #+#    #+#             */
/*   Updated: 2024/11/07 21:28:33 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include "string"

class MateriaSource : virtual public IMateriaSource
{
	public:

/*                                     constructor                            */
		
		MateriaSource();
		MateriaSource(MateriaSource const & rp);
		virtual ~MateriaSource();

/*                                     func                                   */

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);

	private:
		AMateria	*_materials[4];
};

#endif