/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:42:09 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/09/21 07:52:19 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : name("Undefined"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) 
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->grade = rhs.grade;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << "Bureaucrat: " << i.getName() << ", Grade : " << i.getGrade() << ".";
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void Bureaucrat::incrementGrade()
{
	if ((this->grade - 1) < 1)
		throw GradeTooHighException();
	else
		this->grade--;
}
void Bureaucrat::decrementGrade()
{
	if ((this->grade + 1) > 150)
		throw GradeTooLowException();
	else
		this->grade++;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::setGrade(int newGrade)
{
	if (newGrade > 150)
		throw GradeTooLowException();
	else if (newGrade < 1)
		throw GradeTooHighException();
	else
		this->grade = newGrade;
}


/* ************************************************************************** */