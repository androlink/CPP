/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:34:57 by gcros             #+#    #+#             */
/*   Updated: 2024/07/24 00:18:37 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCAVTRAP_HPP_
#define _SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{

	public:
	/*	constructor	*/
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &value);
		~ScavTrap();

	/*	utils	*/
		ScavTrap		&operator=(const ScavTrap &value);
		virtual void	attack(const std::string& target);
		void			guardGate();


	private:

};

#endif // _SCAVTRAP_HPP_
