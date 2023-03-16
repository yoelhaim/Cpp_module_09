/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:22:29 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/03/16 21:47:57 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>




std::string trim(std::string str)
{
    std::string tmp;
    size_t i = 0;
    size_t j = 0;
    for (; i < str.length() && str[i] == ' '; i++)
    {
    }
    for (j = str.length() - 1; i >= 0 && str[j] == ' '; j--)
    {
    }
    return (str.substr(i, j + 1));
}

BitcoinExchange::BitcoinExchange(std::string nameFile)
{
    std::ifstream file(nameFile);
    std::string line;

    while (getline(file, line))
    {
        char *v = strtok((char *)line.c_str(), ",");
        std::string date = v;
        v = strtok(NULL, "|");
        std::string amount = v;
        if (date == "date")
            continue;
        try
        {
            _dataBase[date] = (stod(amount));
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
{
    *this = ref;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref)
{
    if (this != &ref)
    {
        _dataBase = ref._dataBase;
    }
    return *this;
}


BitcoinExchange::~BitcoinExchange()
{
    _dataBase.clear();
}


size_t BitcoinExchange::checkValidDAte(std::string date)
{
    char *v = strtok((char *)date.c_str(), "-");
    std::string y = trim(v);
    v = strtok(NULL, "-");
    std::string m =trim(v) ;
    v = strtok(NULL, "-");
    std::string d = trim(v);
    date = y +  "-"+m +"-"+ d;
    if (y.empty() || m.empty() || d.empty())
        return (std::cerr << "Error: bad inputs => " << date << std::endl, 0);
    if (y.length() != 4 || m.length() != 2 || d.length() != 2)
        return (std::cerr << "Error: bad input => " << date << std::endl, 0);
    else if (atoi(m.c_str()) < 0 || atoi(m.c_str()) > 12)
        return (std::cerr << "Error: bad input => " << date << std::endl, 0);
    else if (atoi(d.c_str()) < 0 || atoi(d.c_str()) > 31)
        return (std::cerr << "Error: bad input => " << date << std::endl, 0);
    else if (atoi(y.c_str()) < 2009 || atoi(y.c_str()) > 2022)
        return (std::cerr << "Error: bad input => " << date << std::endl, 0);
    return 1;
}


void BitcoinExchange::addTransaction(std::string date, double amount)
{
    if (date != "date")
    {
        if (checkValidDAte(date))
        {
            if (_dataBase.find(date) != _dataBase.end())
            {
                if (_dataBase[date] != -2)
                    std::cout << date << " " << _dataBase[date] * amount << std::endl;
            }
            else
            {
                _dataBase[date] = -2;
                std::map<std::string, double>::iterator it = _dataBase.lower_bound(date);
                it--;
                std::cout << date << " " << it->second * amount << std::endl;
                _dataBase.erase(date);
            }
        }
    }
}

std::map<std::string, double> BitcoinExchange::getDataBase()
{
    return _dataBase;
}