/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:49:38 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/17 15:49:07 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <strings.h>

struct Contact
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string login;
	std::string postalAddress;
	std::string emailAddress;
	std::string phoneNumber;
	std::string birthdayDate;
	std::string favoriteMeal;
	std::string underwearColor;
	std::string darkestSecret;
}

int main()
{
	std::string command;
	Contact contacts[9];

	std::cout << "Shitty phonebook :"
		<< "Usage:\n" << "\tSEARCH: ??\n" << "\tADD: ??\n" << "\tEXIT\n";
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