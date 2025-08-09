/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:55:32 by gcros             #+#    #+#             */
/*   Updated: 2025/02/12 21:36:58 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <iostream>

void	initExceptionHighTest()
{
	std::cout << "___" << __func__ << "___" << std::endl;
	try
	{
		Bureaucrat b("bruce", 0);
		std::cout << b << std::endl;
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
		Bureaucrat b("bruce", 200);
		std::cout << b << std::endl;
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
		Bureaucrat b("bruce", 150);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	basicIncrementTest()
{
	std::cout << "___" << __func__ << "___" << std::endl;
	try
	{
		Bureaucrat b("bruce", 150);
		b.gradeIncrement();
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	exceptionIncrementTest()
{
	std::cout << "___" << __func__ << "___" << std::endl;
	try
	{
		Bureaucrat b("bruce", 1);
		b.gradeIncrement();
		std::cout << b << std::endl;
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
	basicIncrementTest();
	exceptionIncrementTest();
}
