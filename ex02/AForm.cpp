/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:19:17 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/09/21 08:19:18 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : name("Undefined"), is_signed(false), gradeSign(150), gradeExec(150)
{
}

AForm::AForm(const AForm &src) : name(src.name), gradeSign(src.gradeSign), gradeExec(src.gradeExec)
{
    *this = src;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : name(name), is_signed(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &AForm::operator=(AForm const &rhs)
{
    if (this != &rhs)
    {
        this->is_signed = rhs.getIs_signed();
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
    o << "AForm: " << i.getName() << ", Is Signed: " << i.getIs_signed() << ", GradeSign: " << i.getGradeSign() << ", getGradeExec: " << i.getGradeExec();
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (!this->is_signed)
    {
        if (bureaucrat.getGrade() <= this->getGradeSign())
            this->is_signed = true;
        else
            throw GradeTooLowException();
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string AForm::getName() const
{
    return this->name;
}
bool AForm::getIs_signed() const
{
    return this->is_signed;
}
const int AForm::getGradeSign() const
{
    return this->gradeSign;
}
const int AForm::getGradeExec() const
{
    return this->gradeExec;
}

/* ************************************************************************** */