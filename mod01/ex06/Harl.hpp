/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:53:27 by gcros             #+#    #+#             */
/*   Updated: 2024/07/13 17:53:16 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HARL_HPP_
# define _HARL_HPP_

#include <string>

class Harl
{
	private :

		std::string _level;
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	idk(void);
		int		get_level(std::string line);
	
	public :
		Harl(void);
		Harl(std::string level);
		void	print();

};

#endif //_HARL_HPP_
