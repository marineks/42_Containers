#ifndef EQUAL_HPP
# define EQUAL_HPP

/* 
https://en.cppreference.com/w/cpp/algorithm/equal

1,3) Returns true if the range [first1, last1) is equal to the range 
[first2, first2 + (last1 - first1)), and false otherwise.

Two ranges are considered equal if they have the same number of elements and, 
for every iterator i in the range [first1,last1), *i equals *(first2 + (i - first1)).

The overloads (1,2,5,6) use operator== to determine if two elements are equal, 
whereas overloads (3,4,7,8) use the given binary predicate p.
p is a binary function that accepts two elements as arguments and performs the 
task it designed .

compare pour chaque element s´ ils sont bien les memes
*/

namespace ft {
	// (1)
	template< class InputIt1, class InputIt2 >
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2){

		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	};



	// (3)
	template< class InputIt1, class InputIt2, class BinaryPredicate >
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p) {

		while (first1 != last1)
		{
			if (!p(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);

	};
}

#endif