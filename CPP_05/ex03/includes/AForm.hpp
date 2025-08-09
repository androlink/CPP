/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 23:43:57 by gcros             #+#    #+#             */
/*   Updated: 2025/01/14 20:03:58 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <inttypes.h>

class Bureaucrat;

class AForm
{
public:
	AForm(std::string name, int32_t sign_grade, int32_t execute_grade);
	AForm(const AForm &rp);
	virtual ~AForm();
	std::string	getName() const;
	uint32_t	getSignGrade() const;
	uint32_t	getExecuteGrade() const;
	bool		isSigned() const;
	void		beSigned(Bureaucrat &bureaucrat);
	void		tryExecute(Bureaucrat const &executor) const;
	virtual void	execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char*	what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		virtual const char*	what() const throw();
	};
	class FormAlreadySignedException : public std::exception
	{
		virtual const char*	what() const throw();
	};
private:
	AForm();
	AForm &operator=(const AForm &rp);
	const std::string	_name;
	const uint8_t		_signGrade;
	const uint8_t		_executeGrade;
	bool			_isSigned;
};

std::ostream &operator<<(std::ostream &os, AForm const &rp);

#endif