/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:44:10 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/09/21 07:58:50 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat bob("Bob", 150);
    try
    {
        bob.incrementGrade(); // 149
        bob.incrementGrade(); // 148
        bob.incrementGrade(); // 147
        bob.incrementGrade(); // 146
        std::cout << bob << std::endl; // -> 146
        bob.setGrade(7);
        std::cout << bob << std::endl; // -> 7
        bob.incrementGrade(); // 6
        bob.incrementGrade(); // 5
        bob.incrementGrade(); // 4
        bob.incrementGrade(); // 3
        bob.incrementGrade(); // 2
        bob.incrementGrade(); // 1
        bob.incrementGrade(); // Throw Exception (can't be executed)
        bob.incrementGrade(); // (can't be executed)
        bob.incrementGrade(); // (can't be executed)
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << bob << std::endl;
    std::cout << std::endl;
    try
    {
        Bureaucrat mim = Bureaucrat("Mim", 9);
        mim.incrementGrade();
        mim.incrementGrade();
        mim.incrementGrade();
        std::cout << mim << std::endl; //
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
