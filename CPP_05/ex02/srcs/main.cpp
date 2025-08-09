/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:55:32 by gcros             #+#    #+#             */
/*   Updated: 2025/02/12 23:02:20 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include <iostream>

void testPresidentialPardonForm()
{
	std::cout << "___" << __func__ << "___" << std::endl;
	try
	{
		Bureaucrat b("Bureaucrat", 1);
		PresidentialPardonForm f("az");
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
		b.executeForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void testRobotomyRequestForm()
{
	std::cout << "___" << __func__ << "___" << std::endl;
	try
	{
		Bureaucrat b("Bureaucrat", 1);
		RobotomyRequestForm f("yeep");
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
		b.executeForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void testShrubberyCreationForm()
{
	std::cout << "___" << __func__ << "___" << std::endl;
	try
	{
		Bureaucrat b("Bureaucrat", 1);
		ShrubberyCreationForm f("tree");
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
		b.executeForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void testGradeTooLowException()
{
	std::cout << "___" << __func__ << "___" << std::endl;
	try
	{
		ShrubberyCreationForm f("tree");
		Bureaucrat b("Bureaucrat", 140);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
		b.executeForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int	main()
{
	testPresidentialPardonForm();
	testRobotomyRequestForm();
	testShrubberyCreationForm();
	testGradeTooLowException();
}
