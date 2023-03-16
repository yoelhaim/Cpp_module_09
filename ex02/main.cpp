/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:01:56 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/03/16 18:54:11 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    std::deque<int> list;
    std::vector<int> vec;
    if (ac == 1)
        return (std::cout << "Error" << std::endl, 0);
    inisialize(av, list, vec);
    

    std::cout << "******** example insert vector *******"<< std::endl;
    // !! inset vector sort
    beforeVector(vec);
    insertSortVector(vec);
    afterVector(vec);

    std::cout << "******** example merge vector *******"<< std::endl;
    // !! merge vector sort
    mergeSortVector(vec);
    afterVector(vec);
    
    std::cout << "******** example insert deque *******"<< std::endl;
    // !! inset deque sort
    beforeDeque(list);
    insertSortDeque(list);
    afterDeque(list);
    
    std::cout << "******** example merge deque *******"<< std::endl;
    // !! merge deque sort
    mergeSortDeque(list);
    afterDeque(list);
}
