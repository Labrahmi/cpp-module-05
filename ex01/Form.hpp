/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:25:23 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/09/20 19:23:49 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

public:
	Form();
	Form(std::string name, int gradeSign, int gradeExec);
	Form(Form const &src);
	~Form();
	Form &operator=(Form const &rhs);
	//
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "GradeTooHighException: Grade is too high!";
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "GradeTooLowException: Grade is too low!";
		}
	};
	//
	const std::string getName() const;
	bool getIs_signed() const;
	const int getGradeSign() const;
	const int getGradeExec() const;
	// 
	void beSigned(Bureaucrat &bureaucrat);
	
private:
	const std::string name;
	bool is_signed;
	const int gradeSign;
	const int gradeExec;
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif /* ************************************************************ FORM_H */