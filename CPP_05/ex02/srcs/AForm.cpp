/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:28:29 by gcros             #+#    #+#             */
/*   Updated: 2025/01/13 01:26:58 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(std::string name, int32_t sign_grade, int32_t execute_grade):
_name(name), _signGrade(sign_grade), _executeGrade(execute_grade), _isSigned(false)
{
	if (sign_grade < 1 || execute_grade < 1)
		throw(AForm::GradeTooHighException());
	if (sign_grade > 150 || execute_grade > 150)
		throw(AForm::GradeTooLowException());
}

AForm::AForm(const AForm &rp):
_name(rp._name), _signGrade(rp._signGrade), _executeGrade(rp._executeGrade), _isSigned(rp._isSigned)
{
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return this->_name;
}

uint32_t AForm::getSignGrade() const
{
	return this->_signGrade;
}

uint32_t AForm::getExecuteGrade() const
{
	return this->_executeGrade;
}

bool AForm::isSigned() const
{
	return this->_isSigned;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_isSigned)
		throw (AForm::FormAlreadySignedException());
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw (AForm::GradeTooLowException());
	this->_isSigned = true;
}

void AForm::tryExecute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw (FormNotSignedException());
	if (this->_executeGrade < executor.getGrade())
		throw (AForm::GradeTooLowException());
	this->execute(executor);
}

AForm::AForm():
_name("NaN"), _signGrade(50), _executeGrade(50), _isSigned(false)
{
}

AForm &AForm::operator=(const AForm &rp)
{
	(void) rp;
	return (*this);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

std::ostream &operator<<(std::ostream &os, AForm const &rp)
{
	os << rp.getName() << ": ";
	if (rp.isSigned())
		os << "signed";
	else
		os << "not signed";
	return (os);
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "form not signed";
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
	return "form already signed";
}
