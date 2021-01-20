/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:49:38 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/19 04:55:53 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

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

	Contact(){}
	~Contact(){}

	void print() {
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

private:
	std::string _toStringField(std::string fieldName, std::string fieldData)
	{
		if (!fieldData.empty())
			return "\t" + fieldName + ": " + fieldData + "\n";
		return "";						
	}
};
class Phonebook
{
	size_t	_i;
	size_t	_cell_width;

	void _requieredField(std::string field, std::string * fieldRef)
	{
		do
		{
			std::cout << field; 
			getline(std::cin,*fieldRef);
			if (fieldRef->empty())
				std::cout << "FIELD REQUIERE !" << std::endl; 							
		} while (fieldRef->empty() && std::cin);
	}
	void _printCell(std::string content){
		std::cout << std::setfill(' ') << std::setw(_cell_width)
			<< (content.size() > _cell_width ?
				content.substr(0, _cell_width-1)+"." : content) << "|";		
	}
	
	void _print_contact()
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

public:
	Contact contacts[MAX_CONTACTS];
	Phonebook(): _i(0), _cell_width(10) {};
	~Phonebook(){};

	void addContact(){
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
	void	searchContact(){
		
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
};

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
		<< "I warned it was a shitty phonebook ! " << std::endl;
	return 0;
}