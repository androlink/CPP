/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:18:23 by gcros             #+#    #+#             */
/*   Updated: 2024/06/10 14:28:46 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*m_zombie = newZombie("mzoo");
	m_zombie->announce();
	randomChump("szoo");
	m_zombie->announce();
	delete m_zombie;
}
