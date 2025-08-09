/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:05:01 by gcros             #+#    #+#             */
/*   Updated: 2025/01/17 02:43:33 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
AForm("ShrubberyCreationForm", 145, 137)
,_target(target)
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream os;
	
	(void) executor;
	os.open((this->_target + "_shrubbery").c_str());
	if (!os.is_open())
		throw std::runtime_error("Can't open file");
	os	<< "   ^   " << "\n"
		<< "  ^^^  " << "\n"
		<< " ^^^^^ " << "\n"
		<< "^^^^^^^" << "\n"
		<< "   |   " << "\n"
		<< "   |   " << "\n"
		<< "   |   " << "\n";
	os.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm():
AForm("ShrubberyCreationForm", 145, 137)
,_target("home")
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rp)
{
	(void)rp;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rp):
AForm(rp)
,_target(rp._target)
{
}