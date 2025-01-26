/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:30:00 by gcros             #+#    #+#             */
/*   Updated: 2024/07/13 17:59:00 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WEAPON_HPP_
# define _WEAPON_HPP_

# include <string>

class Weapon
{
private:
	std::string	type;
public:
	Weapon(std::string type);
	Weapon(void);
	~Weapon(void);
	void		setType(std::string type);
	const std::string	&getType(void);
};

#endif //_WEAPON_HPP_