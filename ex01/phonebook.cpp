/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:49:38 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/16 19:08:09 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <strings.h>

int main()
{
	std::string command;

	while (true)
	{
		std::cin >> command;
		if (!command.compare("SEARCH"))
			std::cout << "SEARCH";
		else if (!command.compare("ADD"))
			std::cout << "ADD";
		else if (!command.compare("EXIT"))
			break;
	}
	return 0;
}