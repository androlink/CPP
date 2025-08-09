/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:37:06 by gcros             #+#    #+#             */
/*   Updated: 2025/03/08 14:48:54 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include <string>

bool	is_int(const std::string &value);
bool	is_double(const std::string &value);
bool	is_char(const std::string &value);
bool	is_float(const std::string &value);
void	print_result(double value);

#endif