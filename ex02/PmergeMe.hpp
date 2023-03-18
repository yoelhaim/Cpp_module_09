/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:20:29 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/03/18 01:33:03 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <deque>
#include <vector>


void inisialize(char **av,std::deque<int> &list, std::vector<int> &vec);
void insertSortVector(std::vector<int> &vec);
void insertSortDeque(std::deque<int> &list);
void mergeSortVector(std::vector<int> &vec);
void mergeSortDeque(std::deque<int> &list);
void beforeVector(std::vector<int> &vec);
void afterVector(std::vector<int> &vec);
void beforeDeque(std::deque<int> &list);
void afterDeque(std::deque<int> &list);
