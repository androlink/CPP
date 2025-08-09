/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:47:19 by gcros             #+#    #+#             */
/*   Updated: 2025/01/17 02:57:11 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target):
AForm("PresidentialPardonForm", 25, 5)
,_target(target)
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	(void) executor;
	std::cout << this->_target
		<< " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm():
AForm("PresidentialPardonForm", 25, 5)
,_target("no one")
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rp):
AForm(rp), _target(rp._target)
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rp)
{
	(void)rp;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

