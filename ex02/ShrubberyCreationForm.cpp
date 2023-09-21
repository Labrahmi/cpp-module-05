/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:24:22 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/09/21 12:19:53 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("Undefined")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		this->target = rhs.target;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i)
{
	// o << "Value = " << i.getValue();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void createAsciiArt(std::string target)
{
	std::ofstream ofs(target + "_shrubbery");
	if (ofs.is_open())
	{
		ofs << "    ^    " << std::endl;
		ofs << "   ^^^   " << std::endl;
		ofs << "  ^^^^^  " << std::endl;
		ofs << " ^^^^^^^ " << std::endl;
		ofs << "    |    " << std::endl;
		ofs.close();
	}
	else
		std::cerr << "Error creating the file!" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIs_signed())
	{
		if (executor.getGrade() <= this->getGradeExec())
			createAsciiArt(this->target);
		else
		{
			std::cout << this->getName() << " Form can't be executed because: " << std::endl;
			throw GradeTooLowException();
		}
	}
	else
		std::cout << this->target << " Form has to be signed first!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */