/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:44:11 by gcros             #+#    #+#             */
/*   Updated: 2024/07/13 17:53:37 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HARL_HPP_
# define _HARL_HPP_

#include <string>

class Harl
{

	private:
	
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:

		void	complain(std::string level);
};

#endif //_HARL_HPP_
