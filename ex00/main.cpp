/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:34:52 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/03/16 21:53:54 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange exchange;
    if (!av[1])
        return (std::cerr << "Error: could not open file." << std::endl, 1);
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
            double number;
            
            if (v != NULL)
            {
                amount = v;
                number = strtod(amount.c_str(), NULL);
                v = strtok(NULL, "|");
            if (v)
                return (std::cerr << "Error" << std::endl, 1);
            }
            else
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            if (number <= -1)
            {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            
           else if (number < INT_MIN || number > INT_MAX)
           {
                    std::cout << "Error: too large a number." << std::endl;
                    continue;
           }
            try
            {
                exchange.addTransaction(date, std::stod(amount));
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
    return 0;
}