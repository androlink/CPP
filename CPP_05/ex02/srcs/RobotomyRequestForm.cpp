/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:21:23 by gcros             #+#    #+#             */
/*   Updated: 2025/01/17 02:57:23 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <iostream>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
AForm("RobotomyRequestForm", 72, 45),
_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rp):
AForm(rp),
_target(rp._target)
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rp)
{
	(void)rp;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	(void) executor;
	if (rand() & 1)
		std::cout << this->_target << "has been robotomized successfully" << std::endl;
	else
		std::cout << "he robotomy failed" << std::endl;
}
