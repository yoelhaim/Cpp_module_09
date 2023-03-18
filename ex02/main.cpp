/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:01:56 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/03/18 01:32:10 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void runAlg(std::vector<int> &vec, std::deque<int> &list)
{
    clock_t _clock;
    if (vec.size() > 1000)
    {
        // !! test vector
        beforeVector(vec);
        _clock = clock();
        mergeSortVector(vec);
        _clock = clock() - _clock;
        double timeV = (double)_clock / CLOCKS_PER_SEC;

        // !! test deque
        _clock = clock();
        mergeSortDeque(list);
        _clock = clock() - _clock;
        double timeD = (double)_clock / CLOCKS_PER_SEC;

        if (timeV < timeD)
            afterVector(vec);
        else
            afterDeque(list);
            
        std::cout << "Time to process a range of " << list.size() << " elements with std::[vector] : " << timeV << std::endl;
      
        std::cout << "Time to process a range of " << list.size() << " elements with std::[deque] : " << timeD << std::endl;
    }
    else
    {
        
         // !! test vector
        beforeVector(vec);
        _clock = clock();
        insertSortVector(vec);
        _clock = clock() - _clock;
        double timeV = (double)_clock / CLOCKS_PER_SEC;

        // !! test deque
        _clock = clock();
        insertSortDeque(list);
        _clock = clock() - _clock;
        double timeD = (double)_clock / CLOCKS_PER_SEC;
        
       if (timeV < timeD)
            afterVector(vec);
        else
            afterDeque(list);
            
        std::cout << "Time to process a range of " << list.size() << " elements with std::[vector] : " << timeV << std::endl;
      
        std::cout << "Time to process a range of " << list.size() << " elements with std::[deque] : " << timeD << std::endl;
        
    }
}

int main(int ac, char **av)
{

    std::deque<int> list;
    std::vector<int> vec;
    if (ac == 1)
        return (std::cout << "Error" << std::endl, 0);
    inisialize(av, list, vec);
    runAlg(vec, list);

   
}
