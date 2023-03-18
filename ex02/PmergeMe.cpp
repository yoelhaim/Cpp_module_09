/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:20:29 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/03/17 20:53:29 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*****************************************************
 *                 INSERT SORT VECTOR                 *
 ******************************************************/

void insertSortVector(std::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        int j = i;
        while (j > 0 && vec[j - 1] > vec[j])
        {
            std::swap(vec[j], vec[j - 1]);
            j--;
        }
    }
}

void mergeSortVector(std::vector<int> &vec)
{
    std::vector<int> vecLeft;
    std::vector<int> vecRight;

    if (vec.size() == 1)
        return;

    size_t mid = vec.size() / 2;

    vecLeft.insert(vecLeft.end(), vec.begin(), vec.begin() + mid);
    vecRight.insert(vecRight.end(), vec.begin() + mid, vec.end());

    mergeSortVector(vecLeft);
    mergeSortVector(vecRight);
    vec.clear();
    
    size_t i = 0, j = 0;
    
    while (i < vecLeft.size() && j < vecRight.size())
    {
        if (vecLeft[i] < vecRight[j])
            vec.push_back(vecLeft[i++]);
        else
            vec.push_back(vecRight[j++]);
    }

    while (i < vecLeft.size() || j < vecRight.size())
    {
        if (i < vecLeft.size())
            vec.push_back(vecLeft[i++]);
        else
            vec.push_back(vecRight[j++]);
    }
}
/*****************************************************
 *                 INSERT SORT DEQUE                 *
 ******************************************************/

void insertSortDeque(std::deque<int> &list)
{
    for (size_t i = 0; i < list.size(); i++)
    {
        int j = i;
        while (j > 0 && list[j - 1] > list[j])
        {
            std::swap(list[j], list[j - 1]);
            j--;
        }
    }
}

void inisialize(char **av, std::deque<int> &list, std::vector<int> &vec)
{
    for (int i = 1; av[i]; i++)
    {
        for (size_t j = 0; j < strlen(av[i]); j++)
        {
            if (!isdigit(av[i][j]))
            {
                list.clear();
                vec.clear();
                std::cout << "Invalid argument" << std::endl;
                exit(1);
            }
        }
        
        double num = static_cast<double>(atof(av[i]));
        if (num > INT_MAX || num < INT_MIN)
        {
            list.clear();
            vec.clear();
            std::cout << "Invalid argument" << std::endl;
            exit(1);
        }
        
        list.push_back(atof(av[i]));
        vec.push_back(atof(av[i]));
    }
}

/*****************************************************
 *              GET DATA BEFORE & AFTER               *
 ******************************************************/
void beforeVector(std::vector<int> &vec)
{
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
void afterVector(std::vector<int> &vec)
{
    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
void beforeDeque(std::deque<int> &list)
{
    std::cout << "Before: ";
    for (size_t i = 0; i < list.size(); i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}
void afterDeque(std::deque<int> &list)
{
    std::cout << "After:  ";
    for (size_t i = 0; i < list.size(); i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}


void mergeSortDeque(std::deque<int> &list)
{
    std::deque<int> listLeft;
    std::deque<int> listRight;

    if (list.size() == 1)
        return;

    size_t mid = list.size() / 2;

    listLeft.insert(listLeft.end(), list.begin(), list.begin() + mid);
    listRight.insert(listRight.end(), list.begin() + mid, list.end());

    mergeSortDeque(listLeft);
    mergeSortDeque(listRight);
    list.clear();
    
    size_t i = 0, j = 0;
    
    while (i < listLeft.size() && j < listRight.size())
    {
        if (listLeft[i] < listRight[j])
            list.push_back(listLeft[i++]);
        else
            list.push_back(listRight[j++]);
    }

    while (i < listLeft.size() || j < listRight.size())
    {
        if (i < listLeft.size())
            list.push_back(listLeft[i++]);
        else
            list.push_back(listRight[j++]);
    }
}
/*****************************************************
 *              end DATA BEFORE & AFTER               *
 ******************************************************/