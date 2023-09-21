/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:10:52 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/09/21 07:53:46 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : name("Undefined"), is_signed(false), gradeSign(150), gradeExec(150)
{
}

Form::Form(const Form &src) : name(src.name), gradeSign(src.gradeSign), gradeExec(src.gradeExec)
{
    *this = src;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : name(name), is_signed(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &Form::operator=(Form const &rhs)
{
    if (this != &rhs)
    {
        this->is_signed = rhs.getIs_signed();
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
    o << "Form: " << i.getName() << ", Is Signed: " << i.getIs_signed() << ", GradeSign: " << i.getGradeSign() << ", getGradeExec: " << i.getGradeExec();
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void Form::beSigned(Bureaucrat &bureaucrat)
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

const std::string Form::getName() const
{
    return this->name;
}
bool Form::getIs_signed() const
{
    return this->is_signed;
}
const int Form::getGradeSign() const
{
    return this->gradeSign;
}
const int Form::getGradeExec() const
{
    return this->gradeExec;
}

/* ************************************************************************** */