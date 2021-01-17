/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:59:29 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/16 19:44:37 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

void str_upper(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (std::islower(str.at(i)))
			str.replace(i, 1, 1, std::toupper(str.at(i)));
}

int main(int ac, char **av)
{
	std::string str;

	if (ac < 2)
		str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac ; i++)
			str += av[i];
		str_upper(str);
	}
	std::cout << str << std::endl;
	return (0);
}