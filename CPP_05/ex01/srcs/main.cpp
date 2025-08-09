/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:55:32 by gcros             #+#    #+#             */
/*   Updated: 2025/02/12 22:12:21 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <iostream>

void	initExceptionHighTest()
{
	std::cout << "___" << __func__ << "___" << std::endl;
	try
	{
		Form f("test", 0, 100);
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	initExceptionLowTest()
{
	std::cout << "___" << __func__ << "___" << std::endl;
	try
	{
		Form f("test", 200, 100);
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	basicTest()
{
	std::cout << "___" << __func__ << "___" << std::endl;
	try
	{
		Form f("test", 100, 50);
		std::cout << f << std::endl;
		Bureaucrat b("albert", 90);
		std::cout << b << std::endl;
		b.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	signExeption()
{
	std::cout << "___" << __func__ << "___" << std::endl;
	try
	{
		Form f("test", 100, 50);
		std::cout << f << std::endl;
		Bureaucrat b("albert", 150);
		std::cout << b << std::endl;
		b.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
int	main()
{
	basicTest();
	initExceptionHighTest();
	initExceptionLowTest();
	signExeption();
}
