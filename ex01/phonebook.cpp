/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:49:38 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/16 02:14:26 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <strings.h>

int main()
{
	char command[8];
	
	while (true)
	{
		std::cin >> command;
		if (!strcmp("SEARCH", command))
			std::cout << "SEARCH";
		else if ("ADD")
			std::cout << "ADD";
		else if ("EXIT")
			break;
	}
	return 0;
}