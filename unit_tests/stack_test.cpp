/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:09:42 by msanjuan          #+#    #+#             */
/*   Updated: 2023/02/10 14:29:53 by msanjuan         ###   ########.fr       */
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
	std::cout << "************* 👀 LET'S RUN SOME TESTS ON STACK 🤓 ***************" << std::endl << std::endl;
	
	ft::stack<int> f_int;	/* f stands for FAKE */
	std::stack<int> t_int;	/* T stands for TRUE */

	/* Testing for Stack of INTS*/
	f_int.push(10);
	t_int.push(10);
	EXPECT_EQ("[INT]", ".push(10) - SIZE()", f_int.size(), t_int.size());
	EXPECT_EQ("[INT]", ".push(10) - EMPTY()", f_int.empty(), t_int.empty());
	EXPECT_EQ("[INT]", ".push(10) - TOP()", f_int.top(), t_int.top());


	f_int.pop();
	t_int.pop();
	EXPECT_EQ("[INT]", ".pop() - SIZE()", f_int.size(), t_int.size());
	EXPECT_EQ("[INT]", ".pop() - EMPTY()", f_int.empty(), t_int.empty());
	

	/* Testing for Stack of std::STRINGS*/
	ft::stack<std::string> f_string;
	std::stack<std::string> t_string;

	EXPECT_EQ("[STR]", "Construct - SIZE()", f_string.size(), t_string.size());
	EXPECT_EQ("[STR]", "Construct - EMPTY()", f_string.empty(), t_string.empty());

	std::string hello = "Hello";
	std::string world = " World!";
	f_string.push(hello);
	t_string.push(hello);
	EXPECT_EQ("[STR]", "Push(hello) 1 - SIZE()", f_string.size(), t_string.size());
	EXPECT_EQ("[STR]", "Push(hello) 1 - EMPTY()", f_string.empty(), t_string.empty());
	EXPECT_EQ("[STR]", "Push(hello) 1 - TOP())", f_string.top(), t_string.top());
	
	f_string.push(world);
	t_string.push(world);
	EXPECT_EQ("[STR]", "Push(world) 2 - SIZE()", f_string.size(), t_string.size());
	EXPECT_EQ("[STR]", "Push(world) 2 - EMPTY()", f_string.empty(), t_string.empty());
	EXPECT_EQ("[STR]", "Push(world) 2 - TOP())", f_string.top(), t_string.top());

	f_string.pop();
	t_string.pop();
	EXPECT_EQ("[STR]", "Pop() 1 - SIZE()", f_string.size(), t_string.size());
	EXPECT_EQ("[STR]", "Pop() 1 - EMPTY()", f_string.empty(), t_string.empty());
	EXPECT_EQ("[STR]", "Pop() 1 - TOP())", f_string.top(), t_string.top());

	
	// checker la complexité
}