/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:17:45 by gcros             #+#    #+#             */
/*   Updated: 2024/06/18 21:04:27 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <string>
#include <iostream>

void	loop(PhoneBook *phonebook);

int	main()
{
	PhoneBook phonebook;

	loop(&phonebook);
}

void	loop(PhoneBook *phonebook)
{
	std::string cmd;
	std::string t;

	do
	{
		cmd = "";
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		std::getline(std::cin, cmd);
		if (cmd.compare("SEARCH") == 0)
		{
			phonebook->search();
		}
		else if (cmd.compare("ADD") == 0)
		{
			phonebook->add();
		}
		else if (cmd.compare("EXIT") == 0)
		{
			break ;
		}
	} while (!std::cin.eof());
	std::cout << "exit" << std::endl;
}
