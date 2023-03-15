/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:22:06 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/03/15 00:16:34 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

int main(int ac, char **av)
{
    std::string str = av[1];
    std::stack<char> s;

    int i = 0, a, b, r;
    while (str[i] != '\0')
    {
       if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' )
       {
        if (s.size() < 2)
        {
            std::cout << "Error" << std::endl;
            return 0;
        }
        b = s.top(); s.pop();
        a = s.top(); s.pop();
        switch (str[i])
        {
        case ('+'):
            r = a + b;
            break;
        case ('-'):
            r = a - b;
            break;
        case ('*'):
            r = a * b;
            break;
        case ('/'):
            r = a / b;
            break;
        }
        s.push(r);
        
       }
       else
        s.push(std::atof(&str[i]));
        i++;
    }
    std::cout << s.top() << std::endl;
    return 0;
}