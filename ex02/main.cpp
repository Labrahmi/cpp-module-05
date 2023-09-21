/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:44:10 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/09/21 16:55:09 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void test_1()
{
    try
    {
        Bureaucrat bob("Bob", 5);
        std::cout << bob << std::endl;

        Bureaucrat alice("Alice", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
}
void test_2()
{
    Bureaucrat bob("Bob", 5);
    ShrubberyCreationForm shrubberyForm("Garden");
    try
    {
        bob.signAForm(shrubberyForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        bob.incrementGrade();
        shrubberyForm.execute(bob);

        RobotomyRequestForm robotomyForm("Target1");
        bob.signAForm(robotomyForm);
        robotomyForm.execute(bob);

        PresidentialPardonForm pardonForm("Target2");
        bob.signAForm(pardonForm);
        pardonForm.execute(bob);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void test_3()
{
    Bureaucrat charlie("Charlie", 150);
    try
    {
        RobotomyRequestForm anotherRobotomyForm("Target3");
        charlie.signAForm(anotherRobotomyForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main(void)
{
    test_1();
    test_2();
    test_3();
    return 0;
}
