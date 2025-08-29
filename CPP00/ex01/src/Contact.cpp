/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:18:33 by mjameau           #+#    #+#             */
/*   Updated: 2025/02/17 12:25:13 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : _first_name(""), _last_name(""), _nickname(""), _phone(""), _secret("")
{
	return;
}

Contact::~Contact()
{
	return;
}

void Contact::setFname(const std::string firstN)
{
	this->_first_name = firstN;
}

void Contact::setLname(const std::string lastN)
{
	this->_last_name = lastN;
}

void Contact::setNickname(const std::string nickname)
{
	this->_nickname = nickname;
}

void Contact::setPhone(const std::string phone)
{
	if (phone.empty())
	{
		std::cout << BOLD RED << "Le numéro de téléphone ne peut pas être vide." << RESET << std::endl;
		return;
	}
	if (phone[0] == '+')
	{
		for (size_t i = 1; i < phone.length(); i++)
		{
			if (!std::isdigit(phone[i]))
			{
				std::cout << BOLD RED << "Le numéro de téléphone contient des caractères non numériques." << RESET << std::endl;
				return ;
			}
		}
	}
	else
	{
		for (size_t i = 0; i < phone.length(); i++)
		{
			if (!std::isdigit(phone[i]))
			{
				std::cout << BOLD RED << "Le numéro de téléphone contient des caractères non numériques." << RESET << std::endl;
				return ;
			}
		}
	}

	this->_phone = phone;
}

void Contact::setSecret(const std::string secret)
{
	this->_secret = secret;
}

const std::string Contact::getFname() const
{
	return this->_first_name;
}

const std::string Contact::getLname() const
{
	return this->_last_name;
}

const std::string Contact::getNickname() const
{
	return this->_nickname;
}

const std::string Contact::getPhone() const
{
	return this->_phone;
}

const std::string Contact::getSecret() const
{
	return this->_secret;
}
