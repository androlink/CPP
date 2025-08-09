/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:21:25 by gcros             #+#    #+#             */
/*   Updated: 2025/02/12 23:00:50 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &rp);
	virtual ~RobotomyRequestForm();
	virtual void	execute(Bureaucrat const & executor) const;

private:
	RobotomyRequestForm();
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &rp);

	const std::string	_target;
};

#endif