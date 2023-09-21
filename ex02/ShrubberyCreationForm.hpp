/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:24:18 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/09/21 09:52:32 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
	// 
	void execute(Bureaucrat const & executor) const;

private:
    std::string target;

};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i);

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */