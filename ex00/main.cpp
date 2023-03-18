/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:34:52 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/03/17 23:50:09 by yoelhaim         ###   ########.fr       */
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
            int len = 0;
            for (size_t i = 0; i < line.size(); i++)
                if (line[i] == '|')
                    len++;
            if (len >= 2 || line.length() == 0){std::cerr << "Error: line." << std::endl;continue;}

            char *v = strtok((char *)line.c_str(), "|");
            std::string date;
            std::string amount;
            if (v != NULL)
                date = v;
            else{std::cerr << "Error: bad input => " << date << std::endl;continue;}
            v = strtok(NULL, "|");
            
            double number;

            if (v != NULL)
            {
                amount = v;
                number = static_cast<double>(atof(amount.c_str()));
                v = strtok(NULL, "|");
                if (v)
                    return (std::cerr << "Error" << std::endl, 1);
                if (checkAmount(trim(amount)))
                    continue;
            }
            else{std::cerr << "Error: bad input => " << date << std::endl;continue;}
            if (number < INT_MIN || number > INT_MAX){std::cout << "Error: too large a number." << std::endl;continue;}
            if (number <= -1 || number > 1000){std::cerr << (number < 0 ? "Error: not a positive number." : "Error: number is Large.") << std::endl;continue;}
            
            exchange.addTransaction(date, number);
        }
    }
    return 0;
}