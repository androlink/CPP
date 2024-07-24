/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:40:37 by gcros             #+#    #+#             */
/*   Updated: 2024/06/18 20:47:34 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

class Contact
{

public:
	Contact(void);
	Contact(std::string	firstname,
		std::string	lastname,
		std::string	nickname,
		std::string	phonenumber,
		std::string	secret);

	void	print(void);
	int		is_valide(void);
	std::string	getFirstname(void);
	std::string	getLastname(void);
	std::string	getNickname(void);
	std::string	getPhonenumber(void);
	std::string	getSecret(void);

	~Contact(void);
private:
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phonenumber;
	std::string	secret;

};


#endif