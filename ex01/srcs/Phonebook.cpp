/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:55:57 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/22 22:01:10 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

#include "Phonebook.hpp"

Contact::Contact(){}
Contact::~Contact(){}

void Contact::print() {
	std::string result;
	result += _toStringField("First name", firstName); 
	result += _toStringField("Last name", lastName); 
	result += _toStringField("Nick name", nickName); 
	result += _toStringField("Phone number", phoneNumber); 
	result += _toStringField("Login", login); 
	result += _toStringField("Postal address", postalAddress); 
	result += _toStringField("Email address", emailAddress); 
	result += _toStringField("Birthday date", birthdayDate); 
	result += _toStringField("Favorite meal", favoriteMeal); 
	result += _toStringField("Underwear color", underwearColor); 
	result += _toStringField("Darkest secret", darkestSecret); 
	std::cout << result;
}

std::string Contact::_toStringField(std::string fieldName, std::string fieldData)
{
	if (!fieldData.empty())
		return "\t" + fieldName + ": " + fieldData + "\n";
	return "";						
}



Phonebook::Phonebook(): _i(0), _cell_width(10) {};
Phonebook::~Phonebook(){};

void Phonebook::addContact(){
	if (_i < MAX_CONTACTS)
	{	
		_requieredField("\tFirst name: ", &contacts[_i].firstName); 
		_requieredField("\tLast name: ", &contacts[_i].lastName); 
		_requieredField("\tNick name: ", &contacts[_i].nickName); 
		std::cout << "\tlogin: "; 
		getline(std::cin, contacts[_i].login);
		std::cout << "\tBirthday date: "; 
		getline(std::cin, contacts[_i].birthdayDate);
		std::cout << "\tpostal address: "; 
		getline(std::cin, contacts[_i].postalAddress);
		std::cout << "\temail address: "; 
		getline(std::cin, contacts[_i].emailAddress);
		_requieredField("\tPhone number: ", &contacts[_i].phoneNumber); 	
		std::cout << "\tFavorite meal: "; 
		getline(std::cin, contacts[_i].favoriteMeal);
		std::cout << "\tUnderwear color: "; 
		getline(std::cin, contacts[_i].underwearColor);
		std::cout << "\tDarkest secret: "; 
		getline(std::cin, contacts[_i].darkestSecret);
		std::cout << "\n\t" << contacts[_i].firstName << " "
			<< contacts[_i].lastName << " added to your phonebook.\n";
		this->_i++;
	}
	else
		std::cout << "\tERROR: Phonebook full !\n"; 
	std::cout << "\t" << _i << "/" << MAX_CONTACTS << " contacts\n"; 
}
void	Phonebook::searchContact(){
	
	if (this->_i == 0)
	{
		std::cout << "Take a curly or add me, Bob DYLAN, 0912345678 :)" <<std::endl;
		return;
	}
	std::cout << std::setfill('-') << std::setw(_cell_width*4+5) << "" <<std::endl;	
	std::cout << "|";	
	_printCell("index");
	_printCell("first name");
	_printCell("last name");
	_printCell("nick name");
	std::cout << std::endl;
	for (size_t i = 0; i < this->_i; i++)
	{
		std::cout << std::setfill('-') << std::setw(_cell_width*4+5) << "" <<std::endl;		
		std::cout << "|" << std::setfill(' ') << std::setw(_cell_width) << i << "|";		
		_printCell(contacts[i].firstName);
		_printCell(contacts[i].lastName);
		_printCell(contacts[i].nickName);
		std::cout << std::endl;
	}
	std::cout << std::setfill('-') << std::setw(_cell_width*4+5) << "" <<std::endl;
	_print_contact();
}

void Phonebook::_requieredField(std::string field, std::string * fieldRef)
{
	do
	{
		std::cout << field; 
		getline(std::cin,*fieldRef);
		if (fieldRef->empty())
			std::cout << "FIELD REQUIERE !" << std::endl; 							
	} while (fieldRef->empty() && std::cin);
}
void Phonebook::_printCell(std::string content){
	std::cout << std::setfill(' ') << std::setw(_cell_width)
		<< (content.size() > _cell_width ?
			content.substr(0, _cell_width-1)+"." : content) << "|";		
}
	
void Phonebook::_print_contact()
{
	size_t index;

	std::cout << "Choose an index: ";
	std::cin >> index;
	if (index < this->_i && !std::cin.fail())
		contacts[index].print();
	else
		std::cout << "Bad index. " << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
