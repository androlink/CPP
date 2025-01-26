/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:44:14 by gcros             #+#    #+#             */
/*   Updated: 2024/07/13 17:55:09 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void	Harl::complain(std::string level)
{
	static void (Harl::* const	flist[])() = {
		&Harl::debug,
		&Harl::error,
		&Harl::info,
		&Harl::warning
	};
	
	std::string	slist[] = {
		"DEBUG",
		"ERROR",
		"INFO",
		"WARNING"
	};

	for (size_t i = 0; i < sizeof(flist) / sizeof(*flist); i++)
		if (level == slist[i])
			(this->*flist[i])();
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]		" << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. \
I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]		" << "I cannot believe adding extra bacon costs more money. \
	You didn’t put enough bacon in my burger! \
If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]	" << "I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]		" << "This is unacceptable! \
I want to speak to the manager now." << std::endl;
}
