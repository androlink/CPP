/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:46:51 by gcros             #+#    #+#             */
/*   Updated: 2024/07/13 17:12:49 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMAN_A_HPP_
# define _HUMAN_A_HPP_

#include "Weapon.hpp"

class HumanA
{

	public :
		HumanA(std::string name, Weapon &weapon);
		void	attack(void);
		
	private :
		Weapon		&weapon;
		std::string	name;

};

#endif //_HUMAN_A_HPP_
