/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:50:11 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/22 22:04:23 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>

#define MAX_CONTACTS 8

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

	Contact();
	~Contact();

	void print();

private:
	std::string _toStringField(std::string fieldName, std::string fieldData);
};


class Phonebook
{
	size_t	_i;
	size_t	_cell_width;

	void _requieredField(std::string field, std::string * fieldRef);
	void _printCell(std::string content);
	void _print_contact();

public:
	Contact contacts[MAX_CONTACTS];
	
	Phonebook();
	~Phonebook();

	void	addContact();
	void	searchContact();
};

#endif
