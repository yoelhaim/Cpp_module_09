/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:22:06 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/03/15 19:05:39 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac , char **av)
{
    if (ac != 2)
        return (std::cout << "Error" << std::endl, 0);
    std::string tokens = av[1];
    tokens = removeSpace(tokens);
    if (!checkValue(tokens))
        return (std::cout << "Error" << std::endl, 0);
try
{
       int result = evalRPN(tokens);
    std::cout << result << std::endl;

}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}

    return 0;
}
