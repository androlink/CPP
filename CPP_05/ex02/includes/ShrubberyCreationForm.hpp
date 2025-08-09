/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:12:27 by gcros             #+#    #+#             */
/*   Updated: 2025/02/12 23:00:56 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(const std::string target);
	virtual ~ShrubberyCreationForm();

	virtual void	execute(Bureaucrat const & executor) const;

private:
	ShrubberyCreationForm();
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &rp);
	ShrubberyCreationForm(const ShrubberyCreationForm &rp);

	const std::string	_target;
};


#endif