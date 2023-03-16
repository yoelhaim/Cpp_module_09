/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:14:24 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/03/15 19:15:55 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int evalRPN(std::string tokens)
{
    std::stack<int> s;
    int n = tokens.size();

    for (int i = 0; i < n; i++)
    {
        char c = tokens[i];

        if (isdigit(c))
        {
            int num = c - '0';
            s.push(num);
        }
        else
        {
            int b = s.top();
            s.pop();
            if (s.size() == 0)
                throw std::out_of_range("Error");
            int a = s.top();
            s.pop();
           

            switch (c)
            {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(a - b);
                break;
            case '*':
                s.push(a * b);
                break;
            case '/':
                s.push(a / b);
                break;
            }
        }
    }

    return s.top();
}

std::string removeSpace(std::string value)
{
    for (size_t i = 0; i < value.size(); i++)
    {
        if (value[i] == ' ')
        {
            value.erase(i, 1);
            i--;
        }
    }
    return value;
}
bool checkValue(std::string value)
{
    int lenOp = 0;
    int lenNum = 0;
    for (size_t i = 0; i < value.size(); i++)
    {
        if (value[i] != '+' && value[i] != '-' && value[i] != '*' && value[i] != '/')
            if (!isdigit(value[i]))
                return false;

        switch (value[i])
        {
        case ('+'):
        case ('-'):
        case ('*'):
        case ('/'):
            lenOp++;
            break;
        default:
            lenNum++;
            break;
        }
    }
    return lenOp != lenNum - 1  ? false : true;
}