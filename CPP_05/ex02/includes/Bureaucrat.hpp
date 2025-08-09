/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:30:38 by gcros             #+#    #+#             */
/*   Updated: 2025/01/17 02:40:37 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <inttypes.h>

class AForm;

class Bureaucrat
{
public:
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int32_t grade);
	~Bureaucrat();
	std::string	getName() const;
	uint32_t	getGrade() const;
	void		gradeIncrement();
	void		gradeDecrement();
	void		signForm(AForm &form);
	void		executeForm(const AForm &form);
	
	class GradeTooHighException : public std::exception
	{
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char*	what() const throw();
	};

private:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &rp);
	Bureaucrat &operator=(const Bureaucrat &rp);
	const std::string	_name;
	uint8_t			_grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &rp);

#endif