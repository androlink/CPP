/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:39:08 by gcros             #+#    #+#             */
/*   Updated: 2024/07/13 17:58:37 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "./Sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	char			*filename = av[1];
	std::string		s1 = av[2],
					s2 = av[3];
	std::ifstream	ifs;
	std::ofstream	ofs;

	ifs.open(filename);
	if (ifs.fail())
	{
		std::cout << "fail to open file: " << filename << std::endl;
		return (2);
	}
	ofs.open(std::string(filename).append(".replace").c_str());
	if (ofs.fail())
	{
		std::cout << "fail to open file: " << std::string(filename) + ".replace"<< std::endl;
		ifs.close();
		return (3);
	}
	while (!ifs.eof())
	{
		std::string line;
		std::getline(ifs, line);
		size_t	i = line.find(s1, 0);
		if (!s1.empty())
			while (i < line.size())
			{
				line.erase(i, s1.size());
				line.insert(i, s2);
				i += s2.size();
				i = line.find(s1, i);
			}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}
