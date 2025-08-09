/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:22:45 by gcros             #+#    #+#             */
/*   Updated: 2025/02/12 23:00:43 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(const std::string target);
	virtual ~PresidentialPardonForm();
	virtual void	execute(Bureaucrat const & executor) const;

private:
	PresidentialPardonForm();
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &rp);
	PresidentialPardonForm(const PresidentialPardonForm &rp);

	const std::string	_target;
};

#endif