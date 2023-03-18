/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:22:29 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/03/18 01:33:53 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


std::string trim(std::string str)
{
   size_t startpos = str.find_first_not_of(" \t");
    if (startpos != std::string::npos)
        str = str.substr(startpos);

    size_t endpos = str.find_last_not_of(" \t");
    if (endpos != std::string::npos)
        str = str.substr(0, endpos + 1);
    return str;
}

bool checkAmount(std::string amount)
{
    bool flag = false;
    size_t i = 0;
    if (amount[i] == '-' || amount[i] == '+')
        i++;
    
    for (; i < amount.size(); i++)
    {
            if ( amount[i] == '.')
                continue;
        if (!isdigit(amount[i]))
        {
            flag = true;
            break;
        }
    }
    if (!isdigit(amount[amount.size() - 1]))
        flag = true;
    if (flag)
        std::cerr << "Error: bad input => " << amount << std::endl;
    return flag;
}

BitcoinExchange::BitcoinExchange(std::string nameFile)
{
    std::ifstream file(nameFile);
    std::string line;

    while (getline(file, line))
    {
        char *v = strtok((char *)line.c_str(), ",");
        std::string date = v;
        v = strtok(NULL, ",");
        double amount =  static_cast<double>(atof(v));
        if (date == "date")
            continue;
        _dataBase[date] = amount;
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
    std::string y = v;
    v = strtok(NULL, "-");
    std::string m = v;
    v = strtok(NULL, "-");
    std::string d = v;
    
    date = y + "-" + m + "-" + d;

    switch(atoi(m.c_str()))
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (atoi(d.c_str()) > 31)
                return (std::cerr << "Error: bad input => " << date << std::endl, 0);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (atoi(d.c_str()) > 30)
                return (std::cerr << "Error: bad input => " << date << std::endl, 0);
            break;
        case 2:
            if (atoi(y.c_str()) % 4 == 0)
            {
                if (atoi(d.c_str()) > 29)
                    return (std::cerr << "Error: bad input => " << date << std::endl, 0);
            }
            else
            {
                if (atoi(d.c_str()) > 28)
                    return (std::cerr << "Error: bad input => " << date << std::endl, 0);
            }
            break;
        
    }
    
    if (y.length() != 4 || m.length() != 2 || d.length() != 2)
        return (std::cerr << "Error: bad input => " << m << std::endl, 0);
    else if (atoi(m.c_str()) < 0 || atoi(m.c_str()) > 12)
        return (std::cerr << "Error: bad input => " << date << std::endl, 0);
    else if (atoi(y.c_str()) < 2009 )
        return (std::cerr << "Error: bad input => " << date << std::endl, 0);
    return 1;
}

void BitcoinExchange::addTransaction(std::string date, double amount)
{

    if (checkValidDAte(trim(date)))
    {
        if (_dataBase.find(date) != _dataBase.end())
        {
            if (_dataBase[date] != -2)
                std::cout << date << " " << _dataBase[date] * amount << std::endl;
        }
        else
        {
            std::map<std::string, double>::iterator it = _dataBase.lower_bound(date);
            if (it == _dataBase.begin())
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                return;
            }
            it--;
            std::cout << date << " " << it->second * amount << std::endl;
        }
    }
}

std::map<std::string, double> BitcoinExchange::getDataBase()
{
    return _dataBase;
}