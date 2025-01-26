/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:53:03 by gcros             #+#    #+#             */
/*   Updated: 2024/11/28 20:19:43 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
	this->_level = "???";
}

Harl::Harl(std::string level)
{
	this->_level = level;
}

void	Harl::print()
{

	switch (this->get_level(this->_level))
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break ;
		default:
			this->idk();
	}
}

int	Harl::get_level(std::string line)
{
	const std::string s_list[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (size_t i = 0; i < sizeof(s_list) / sizeof(*s_list); i++)
		if (line == s_list[i])
			return (i);
	return (-1);
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]\n" << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. \
I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]\n" << "I cannot believe adding extra bacon costs more money. \
	You didn’t put enough bacon in my burger! \
If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]\n" << "I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]\n" << "This is unacceptable! \
I want to speak to the manager now." << std::endl;
}

void	Harl::idk(void)
{
	std::cout << "[UNKNOWN]\n" << "WTF" << std::endl;
}
