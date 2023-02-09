#include "srcs/stack.hpp"
// #include "vector.hpp"
// #include "map.hpp"
// #include "set.hpp"

#include <iostream>

#include "unit_tests/stack_test.cpp"

void	runAllTests()
{
	RunStackTests();
	//RunIterTests();
	//RunVectorTests();
	//RunMapTests();
	//RunSetTests();
}

int	main()
{
	try 
	{ 
		runAllTests();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}