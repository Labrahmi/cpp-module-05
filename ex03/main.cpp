/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:44:10 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/09/22 08:45:54 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(int argc, char const *argv[])
{
    Intern intern;
    AForm *form;
    Bureaucrat bob("bob", 1);
    form = intern.makeForm("Shrubbery", "Bender");
    if (form)
    {
        bob.signAForm(*form);
        form->execute(bob);
    }
    return 0;
}
