/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:28:36 by gcros             #+#    #+#             */
/*   Updated: 2025/01/17 15:04:42 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(Intern const & intern)
{
	*this = intern;
}

Intern & Intern::operator=(Intern const & intern)
{
	(void)intern;
	return *this;
}

Intern::~Intern()
{
}

static inline AForm *createShrubberyCreationForm(const std::string & target)
{
	return new ShrubberyCreationForm(target);
}

static inline AForm *createRobotomyRequestForm(const std::string & target)
{
	return new RobotomyRequestForm(target);
}

static inline AForm *createPresidentialPardonForm(const std::string & target)
{
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(const std::string & form_name, const std::string & target)
{
	std::string	form_list[] = {"shrubbery creation",
		"robotomy request",
		"presidential pardon"};
	AForm		*(*form_func[])(const std::string &) = {&createShrubberyCreationForm,
		&createRobotomyRequestForm,
		&createPresidentialPardonForm};

	for (size_t i = 0; i < form_list->length(); i++)
		if (form_list[i] == form_name)
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return form_func[i](target);
		}
	std::cout << "Intern can't create " << form_name << std::endl;
	return (NULL);
}