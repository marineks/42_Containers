// #include "stack.hpp"
#include "Stack.hpp"
#include <stack>
#include <string>
#include <iostream>

/* ANSI Colors */
# define CYAN "\e[0;36m"
# define B_RED "\e[0;31m"
# define B_GREEN "\e[0;32m"
# define RESET "\e[0m"


template <typename T, typename U>
void EXPECT_EQ(const char *testName, T myContainer, U trueContainer)
{
	if (myContainer == trueContainer)
		std::cout << CYAN << testName << " : " << RESET << \
		((myContainer == trueContainer) ? "\e[0;32mOK. ✅" : "\e[0;31mKO.❌")\
		<< RESET << std::endl;
}

void	RunStackTests()
{
	std::cout << "******************** 👀 LET'S RUN SOME TESTS ON STACK 🤓 ***********************" << std::endl << std::endl;
	ft::stack<int> f_int; /* f stands for FAKE */
	std::stack<int> t_int; /* T stands for TRUE */

	/**/
	f_int.push(10);
	t_int.push(10);
	EXPECT_EQ("[INT] stack.push(10) - SIZE()", f_int.size(), t_int.size());
	EXPECT_EQ("[INT] stack.push(10) - EMPTY()", f_int.empty(), t_int.empty());
	EXPECT_EQ("[INT] stack.push(10) - TOP()", f_int.top(), t_int.top());


	f_int.pop();
	t_int.pop();
	EXPECT_EQ("[INT] stack.pop() - SIZE()", f_int.size(), t_int.size());
	EXPECT_EQ("[INT] stack.pop() - EMPTY()", f_int.empty(), t_int.empty());
	

	// faire la meme chose pour des strings
	
	// Tester chacun des membres types 
	// Tester chacune des members functions
	// tester les operateurs

	// checker la complexité

	// faire un setup iomanip
}