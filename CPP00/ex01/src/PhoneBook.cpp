/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:18:23 by mjameau           #+#    #+#             */
/*   Updated: 2025/07/23 15:08:58 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0), _index(0)
{
	return;
}

PhoneBook::~PhoneBook()
{
	return;
}

bool PhoneBook::getIn(const std::string &prompt, std::string &input)
{
	std::cout << prompt;
	if (std::getline(std::cin, input))
	{
		if (input.empty())
		{
			std::cout <<  BOLD RED << "Input cannot be empty ❌" << RESET << std::endl;
			return (false);
		}
		return (true);
	}
	else
	{
		if (std::cin.eof())
		{
			std::cout << " " << std::endl;
			this->~PhoneBook();
			exit(0);
		}
		std::cin.clear();
		return (false);
	}
}

void PhoneBook::addContact()
{
	Contact contact;
	std::string input;

	std::cout << " " << std::endl;
	while(!getIn(BOLD YELLOW"First Name : " RESET, input)) {}
	contact.setFname(input);
	while(!getIn(BOLD YELLOW"Last Name : " RESET, input)) {}
	contact.setLname(input);
	while(!getIn(BOLD YELLOW"Nickname : " RESET, input)) {}
	contact.setNickname(input);

	bool validPhone = false;
	while (!validPhone)
	{
		while(!getIn(BOLD YELLOW"Phone : " RESET, input)) {}
		contact.setPhone(input);
		if (contact.getPhone().empty())
			std::cout <<  BOLD RED << "Le numéro de téléphone n'est pas valide. Essayez encore." << RESET << std::endl;
		else
			validPhone = true;

	}
	while(!getIn(BOLD YELLOW"Darkest secret : " RESET, input)) {}
	contact.setSecret(input);
	this->insertContact(contact);
	std::cout << BOLD GREEN << "Contact added ! 🎉" << RESET << "\n" << std::endl;
}

void PhoneBook::insertContact(const Contact &contact)
{
	if (this->_index == 8)
		this->_index = 0;
	this->_repertory[this->_index] = contact;
	this->_index++;
	if (this->_count < 8)
		this->_count++;
}

void PhoneBook::searchContact() const
{
	int index;
	std::string input;

	if (this->_count == 0)
	{
		std::cout << BOLD BLUE << "PhoneBook is empty 😢" << RESET << std::endl;
		return;
	}
	else
		this->displayContacts();
	do
	{
		std::cout << BOLD BLUE << "Search a contact at index 🔎 : " << RESET;
		if (!std::getline(std::cin, input))
		{
			std::cout << " " << std::endl;
			exit(0);
		}
		if (!input.empty())
		{
			try
			{
				index = stringToInt(input);
				if (index < 0 || index >= this->_count)
					std::cout << BOLD RED << "Contact not found ❌" << RESET << std::endl;
				else
					break;
			}
			catch(const std::invalid_argument &e)
			{
				std::cout << BOLD RED << "Enter a numeric index. ❌" << RESET << std::endl;
			}
		}
		else
			std::cout << BOLD RED << "Index cannot be empty ❌" << RESET << std::endl;
	} while (true);
	this->displayContact(index);
}

void PhoneBook::displayContacts() const
{
	std::cout << std::endl << BOLD WHITE << std::setw(10)<< "Index" << "|"
	<< std::setw(10) << "FirstName" << "|" << std::setw(10) <<
	"LastName" << "|" << std::setw(10) << "Nickname" << std::endl;

	for(int i = 0; i < this->_count; i++)
	{
		std::cout << std::setw(10) << i << "|"
		<< std::setw(10) << FormatTrunc(_repertory[i].getFname())
		<< "|" << std::setw(10) << FormatTrunc(_repertory[i].getLname())
		<< "|" << std::setw(10) << FormatTrunc(_repertory[i].getNickname()) << std::endl;
	}
	std::cout << " " << std::endl;
}

void PhoneBook::displayContact(int i) const
{
	Contact contact;
	contact = this->_repertory[i];
	std::cout << std::endl
	<<BOLD WHITE << "First Name : " << contact.getFname() << std::endl
	<< "Last name : " << contact.getLname() << std::endl
	<< "Nickname : " << contact.getNickname() << std::endl
	<< "Phone number : " << contact.getPhone() << std::endl
	<< "Darkest Secret : " << contact.getSecret() << RESET << "\n" << std::endl;
}
