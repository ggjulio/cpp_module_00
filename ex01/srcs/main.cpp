/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:49:38 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/22 22:05:27 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.hpp"

void print_usage(void)
{
	std::cout << "Usage:\n"
		<< "\tSEARCH: obvious\n" << "\tADD   : obvious\n" << "\tEXIT  : obvious\n";
}

int main()
{
	Phonebook	phonebook;
	std::string command;

	std::cout << "Shitty phonebook" << std::endl;
	print_usage();
	while (!std::cin.fail())
	{
		std::cout << "$>  ";
		getline(std::cin, command);
		if (!command.compare("SEARCH"))
			phonebook.searchContact();
		else if (!command.compare("ADD"))
			phonebook.addContact();
		else if (!command.compare("EXIT"))
			break;
		else {
			std::cout << "Command not found: " << command<< std::endl;
			print_usage();	
		}
	}
	std::cout << "You lost ALL your friends." << std::endl
		<< "I told you it was a shitty phonebook ! " << std::endl;
	return 0;
}
