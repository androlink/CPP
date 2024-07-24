/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:46:48 by gcros             #+#    #+#             */
/*   Updated: 2024/07/13 17:12:37 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMAN_B_HPP_
# define _HUMAN_B_HPP_

#include "Weapon.hpp"

class HumanB
{

	public :
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);
		void	attack(void);
		void	setWeapon(Weapon weapon);
		
	private :
		Weapon		*weapon;
		std::string	name;

};

#endif //_HUMAN_B_HPP_
