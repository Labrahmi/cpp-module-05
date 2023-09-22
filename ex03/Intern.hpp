/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 08:02:15 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/09/22 08:44:19 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{

public:
	Intern();
	Intern(Intern const &src);
	~Intern();
	Intern &operator=(Intern const &rhs);

	AForm *makeForm(std::string form_name, std::string target);

private:
	static AForm *createRobotomy(const std::string &target);
	static AForm *createShrubbery(const std::string &target);
	static AForm *createPresidential(const std::string &target);
};

typedef AForm *(*CreationFunc)(const std::string &target);

std::ostream &operator<<(std::ostream &o, Intern const &i);

#endif /* ********************************************************** INTERN_H */