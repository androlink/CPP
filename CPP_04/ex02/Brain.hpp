/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:19:36 by gcros             #+#    #+#             */
/*   Updated: 2024/07/29 16:39:17 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "string"
#include "iostream"

class Brain
{
	public:
		Brain();
		Brain(const Brain &brain);
		~Brain();

		Brain &operator=(const Brain &rp);
		void	setIdeaAt(std::string newIdea, int index);
		std::string	getIdeaAt(int index) const;

	private:
		std::string	ideas[100];

};

#endif