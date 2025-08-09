/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:36:35 by gcros             #+#    #+#             */
/*   Updated: 2025/02/12 21:27:28 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const Bureaucrat &rp):
_name(rp._name)
{
	this->_grade = rp.getGrade();
}

Bureaucrat::Bureaucrat(std::string name):
_name(name), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int32_t grade):
_name(name)
{
	if (grade < 1)
		throw(GradeTooHighException());
	if (grade > 150)
		throw(GradeTooLowException());
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rp)
{
	this->_grade = rp.getGrade();
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

uint32_t Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::gradeIncrement()
{
	if (this->_grade == 1)
		throw(GradeTooHighException());
	else
		this->_grade--;
}

void Bureaucrat::gradeDecrement()
{
	if (this->_grade == 150)
		throw(GradeTooLowException());
	else
		this->_grade++;
}

Bureaucrat::Bureaucrat():
_name("rookie"), _grade(150)
{
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &rp)
{
	os << rp.getName() << ", bureaucrat grade " << (int)rp.getGrade();
	return (os);
}
