/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 08:02:19 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/09/22 08:45:21 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &Intern::operator=(Intern const &rhs)
{
	return *this;
}

std::ostream &operator<<(std::ostream &o, Intern const &i)
{
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm *Intern::createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

std::string ft_tolower(std::string &src)
{
	int i = 0;
	while (src[i])
	{
		src[i] = tolower(src[i]);
		i++;
	}
	return src;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	CreationFunc CreationFunctions[3];
	std::string CreationFunctionsNames[3];
	//
	CreationFunctions[0] = &Intern::createRobotomy;
	CreationFunctions[1] = &Intern::createShrubbery;
	CreationFunctions[2] = &Intern::createPresidential;
	CreationFunctionsNames[0] = "robotomy";
	CreationFunctionsNames[1] = "shrubbery";
	CreationFunctionsNames[2] = "presidential";
	//
	formName = ft_tolower(formName);
	for (int i = 0; i < 3; i++)
	{
		if (formName.find(CreationFunctionsNames[i]) != std::string::npos)
			return CreationFunctions[i](target);
	}
	return NULL;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */