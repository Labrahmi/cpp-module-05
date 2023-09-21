/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:25:23 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/09/20 19:23:49 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

public:
	AForm();
	AForm(std::string name, int gradeSign, int gradeExec);
	AForm(AForm const &src);
	~AForm();
	AForm &operator=(AForm const &rhs);
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
	virtual void execute(Bureaucrat const & executor) const = 0;
private:
	const std::string name;
	bool is_signed;
	const int gradeSign;
	const int gradeExec;
};

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif /* ************************************************************ AForm_H */