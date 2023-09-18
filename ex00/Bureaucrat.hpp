/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:42:15 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/09/18 18:04:28 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &rhs);
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
	int getGrade() const;
	void setGrade(int newGrade);
	void incrementGrade();
	void decrementGrade();

private:
	const std::string name;
	int grade;
};

// You will provide getters for both these attributes: getName() and getGrade(). Implement also two member functions to increment or decrement the bureaucrat grade. If
// the grade is out of range, both of them will throw the same exceptions as the constructor

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif /* ****************************************************** BUREAUCRAT_H */