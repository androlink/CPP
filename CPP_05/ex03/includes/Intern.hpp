/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:28:32 by gcros             #+#    #+#             */
/*   Updated: 2025/01/17 14:45:26 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
public:
	Intern();
	Intern(Intern const & intern);
	Intern & operator=(Intern const & intern);
	~Intern();

	AForm * makeForm(std::string const & form_name, std::string const & target);
	
private:

};


#endif