/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:35:49 by gcros             #+#    #+#             */
/*   Updated: 2025/05/09 13:52:50 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void	swap(T &p1, T &p2)
{
	T t1 = p1;

	p1 = p2;
	p2 = t1;
}

template<typename T>
const T	&min(const T &p1, const T &p2)
{
	return (p1 < p2? p1 : p2);
}

template<typename T>
const T	&max(const T &p1, const T &p2)
{
	return (p1 > p2? p1 : p2);
}

#endif