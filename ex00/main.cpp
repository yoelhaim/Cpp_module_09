/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:34:52 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/03/15 02:41:20 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
    BitcoinExchange exchange;
    if (!av[1])
        return (std::cerr << "Error: No input file" << std::endl, 1);
    if (ac != 2)
        return (std::cerr << "Error: Too many arguments" << std::endl, 1);
    std::string inputFile = av[1];
    std::ifstream file(inputFile);
    if (!file.is_open())
        return (std::cerr << "Error: File not found" << std::endl, 1);
    else
    {
        std::string line;
        while (std::getline(file, line))
        {
            char *v = strtok((char *)line.c_str(), "|");
            std::string date = v;
            v = strtok(NULL, "|");
            std::string amount;
            if (v != NULL)
                 amount = v;
            else
            {
                std::cerr << "Error: bad input => "<< date << std::endl;
                continue;
            }
               if (atoi(amount.c_str()) == -1)
                    std::cerr << "Error: not a positive number." << std::endl;
               else if (atoi(amount.c_str()) <  0)
                    std::cout << "Error: too large a number." << std::endl;
                else
                {
                   try
                   {
                       exchange.addTransaction(date, std::stod(amount));
                   }
                   catch(const std::exception& e)
                   {
                       std::cerr << e.what() << '\n';
                   }
                }
        }
    }
    return 0;
}