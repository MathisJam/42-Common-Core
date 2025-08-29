/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:18:25 by mjameau           #+#    #+#             */
/*   Updated: 2025/02/17 12:23:15 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "Contact.hpp"
#include "Format.hpp"

#define BOLD "\033[1m"
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		bool getIn(const std::string &prompt, std::string &input);
		void addContact();
		void insertContact(const Contact &contact);
		void searchContact() const;
		void displayContacts() const;
		void displayContact(int i) const;

	private:
		Contact _repertory[8];
		int _count;
		int _index;

};

#endif
