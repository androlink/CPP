/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:40:08 by gcros             #+#    #+#             */
/*   Updated: 2024/06/10 14:45:03 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *zombie_horde = zombieHorde(20, "michel");

	for (int i = 0; i < 20; i++)
		zombie_horde[i].announce();
	delete[] zombie_horde;
}
