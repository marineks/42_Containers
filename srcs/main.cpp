#include "Stack.hpp"
// #include "vector.hpp"
// #include "map.hpp"
// #include "set.hpp"

#include <iostream>

#include "/mnt/nfs/homes/msanjuan/Documents/Projets_Github/42_Containers/unit_tests/stack_test.cpp"

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