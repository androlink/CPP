/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:55:32 by gcros             #+#    #+#             */
/*   Updated: 2025/04/16 18:15:37 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include <iostream>
#include "../includes/Intern.hpp"
#include <exception>

void testPresidentialPardonForm()
{
	std::cout << "___" << __func__ << "___" << std::endl;
	AForm *f = NULL;
	try
	{
		Bureaucrat b("Bureaucrat", 1);
		f = Intern().makeForm("presidential pardon", "az");
		if (f == NULL)
			throw std::exception();
		std::cout << *f << std::endl;
		b.signForm(*f);
		std::cout << *f << std::endl;
		b.executeForm(*f);
		std::cout << *f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete f;
}

void testRobotomyRequestForm()
{
	std::cout << "___" << __func__ << "___" << std::endl;
	AForm *f = NULL;
	try
	{
		Bureaucrat b("Bureaucrat", 1);
		f = Intern().makeForm("robotomy request", "yeep");
		if (f == NULL)
			throw std::exception();
		std::cout << *f << std::endl;
		b.signForm(*f);
		std::cout << *f << std::endl;
		b.executeForm(*f);
		std::cout << *f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete f;
}

void testShrubberyCreationForm()
{
	std::cout << "___" << __func__ << "___" << std::endl;
	AForm *f = NULL;
	try
	{
		Bureaucrat b("Bureaucrat", 1);
		f = Intern().makeForm("shrubbery creation", "tree");
		if (f == NULL)
			throw std::exception();
		std::cout << *f << std::endl;
		b.signForm(*f);
		std::cout << *f << std::endl;
		b.executeForm(*f);
		std::cout << *f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete f;
}

void testUnknowForm()
{
	std::cout << "___" << __func__ << "___" << std::endl;
	AForm *f = NULL;
	try
	{
		f = Intern().makeForm("49.3", "mick");
		if (f == NULL)
			throw std::exception();
		Bureaucrat b("Bureaucrat", 140);
		std::cout << *f << std::endl;
		b.signForm(*f);
		std::cout << *f << std::endl;
		b.executeForm(*f);
		std::cout << *f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete f;
}

int	main()
{
	testPresidentialPardonForm();
	testRobotomyRequestForm();
	testShrubberyCreationForm();
	testUnknowForm();
}
