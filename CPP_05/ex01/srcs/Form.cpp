/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:28:29 by gcros             #+#    #+#             */
/*   Updated: 2025/02/12 22:42:09 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form(std::string name, int32_t sign_grade, int32_t execute_grade):
_name(name), _signGrade(sign_grade), _executeGrade(execute_grade), _isSigned(false)
{
	if (sign_grade < 1 || execute_grade < 1)
		throw(Form::GradeTooHighException());
	if (sign_grade > 150 || execute_grade > 150)
		throw(Form::GradeTooLowException());
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return this->_name;
}

uint32_t Form::getSignGrade() const
{
	return this->_signGrade;
}

uint32_t Form::getExecuteGrade() const
{
	return this->_executeGrade;
}

bool Form::isSigned() const
{
	return this->_isSigned;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_isSigned)
		throw (Form::FormAlreadySignedException());
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw (Form::GradeTooLowException());
	this->_isSigned = true;
}

Form::Form():
_name("NaF"), _signGrade(50), _executeGrade(50), _isSigned(false)
{
}

Form::Form(const Form &rp):
_name(rp._name), _signGrade(rp._signGrade), _executeGrade(rp._executeGrade), _isSigned(rp._isSigned)
{
}

Form &Form::operator=(const Form &rp)
{
	(void) rp;
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

std::ostream &operator<<(std::ostream &os, Form const &rp)
{
	os << "form: " << rp.getName() << " ";
	if (rp.isSigned())
		os << "signed";
	else
		os << "not signed";
	return (os);
}

const char *Form::FormAlreadySignedException::what() const throw()
{
	return "form already signed";
}
