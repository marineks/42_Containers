/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:13:54 by msanjuan          #+#    #+#             */
/*   Updated: 2023/02/10 18:19:03 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Stack.hpp" // my stack
#include <stack>	// official stack
#include <string>
#include <iostream> // to use std::cout
#include <iomanip> // for formatting

/* ANSI Colors */
# define CYAN "\e[0;36m"
# define YELLOW "\e[1;33m"
# define B_RED "\e[0;31m"
# define B_GREEN "\e[0;32m"
# define RESET "\e[0m"


template <typename T, typename U>
void EXPECT_EQ(const char* testSuite, const char *testName, T myContainer, U trueContainer)
{
	std::cout << YELLOW << testSuite << CYAN << std::setw(30) << testName << " : "  << RESET \
			  << ((myContainer == trueContainer) ? "\e[0;32mOK. ✅" : "\e[0;31mKO.❌")\
			  << RESET << std::endl;
}

void	RunStackTests()
{
	std::cout << "************* 👀 LET'S RUN SOME TESTS ON THE ITERATORS 🥳 ***************" << std::endl << std::endl;
	
	/* Iterator traits */
	ft::stack<int>	f_stack;
	std::stack<int>	t_stack;
	
	for (size_t i = 0; i < 5; i++)
		f_stack.push(1);
	for (size_t j = 0; j < 5; j++)
		t_stack.push(1);

	
}