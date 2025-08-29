/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:18:30 by mjameau           #+#    #+#             */
/*   Updated: 2025/02/17 12:24:52 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

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

class Contact
{
	public:
		Contact();
		~Contact();
		void setFname(const std::string firstN);
		void setLname(const std::string lastN);
		void setNickname(const std::string nickname);
		void setPhone(const std::string phone);
		void setSecret(const std::string secret);

		const std::string getFname() const;
		const std::string getLname() const;
		const std::string getNickname() const;
		const std::string getPhone() const;
		const std::string getSecret() const;

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone;
		std::string _secret;

};

#endif
