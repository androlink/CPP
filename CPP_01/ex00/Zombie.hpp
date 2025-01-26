/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:43:32 by gcros             #+#    #+#             */
/*   Updated: 2024/06/10 14:18:43 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public :
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);

	private :

		std::string	name;


	
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif