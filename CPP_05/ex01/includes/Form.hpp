/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 23:43:57 by gcros             #+#    #+#             */
/*   Updated: 2025/02/12 22:24:26 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <inttypes.h>

class Bureaucrat;

class Form
{
public:
	Form(std::string name, int32_t sign_grade, int32_t execute_grade);
	~Form();
	std::string	getName() const;
	uint32_t	getSignGrade() const;
	uint32_t	getExecuteGrade() const;
	bool		isSigned() const;
	void		beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char*	what() const throw();
	};
	class FormAlreadySignedException : public std::exception
	{
		virtual const char*	what() const throw();
	};
private:
	Form();
	Form(const Form &rp);
	Form &operator=(const Form &rp);
	const std::string	_name;
	const uint8_t		_signGrade;
	const uint8_t		_executeGrade;
	bool			_isSigned;
};

std::ostream &operator<<(std::ostream &os, Form const &rp);

#endif