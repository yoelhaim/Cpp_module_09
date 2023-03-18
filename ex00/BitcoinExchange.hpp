/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:22:24 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/03/17 17:02:28 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <map>

class BitcoinExchange
{
private:
    std::map<std::string, double> _dataBase;
public:
    BitcoinExchange(std::string file = "data.csv");
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange &operator=(const BitcoinExchange &src);
    void addTransaction(std::string date, double amount);
    size_t checkValidDAte(std::string date);
    std::map<std::string, double> getDataBase();
};

std::string trim(std::string str);
bool checkAmount(std::string amount);

