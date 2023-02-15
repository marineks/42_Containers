#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator.hpp"
# include "iterator_traits.hpp"

# include <memory> // for std::addressof

namespace ft {
		
	template <class Iter>
	class reverse_iterator {
		protected:
			iterator_type	current;
		public:
			/* Member types*/
			typedef				Iter											iterator_type;
			typedef typename	ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename	ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename	ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename	ft::iterator_traits<Iter>::pointer				pointer;
			typedef typename	ft::iterator_traits<Iter>::reference			reference;
			
			
			/* Constructors */
			reverse_iterator(): current() {}; // default
			explicit reverse_iterator(Iter x): current(x) {}; // param
			template <class U>
				reverse_iterator(const reverse_iterator<U>& other): current(other.current) {}; // copy
			template< class U >
				reverse_iterator& operator=(const reverse_iterator<U>& other): current(other.base) { return (*this) }; // affectation

			/* Member functions*/
			iterator_type base() const { // accesses the underlying iterator
				return (current);
			};

			reference operator*() const {
				Iter tmp = current;
				return (*--tmp);
			};

			pointer operator->() const { 
				return std::addressof(operator*());
			};

			reference operator[](difference_type n) const {
				return (*this + n); // *(*this + n) ??
			};
			
			/* 1-2) Pre-increments or pre-decrements by one respectively. */
			reverse_iterator& operator++(){
				--current; // ne pas oublier qu'on est dans le reverse, donc normal que dans le ++ on --!
				return (*this);
			};

		
			reverse_iterator& operator--(){
				++current;
				return (*this);
			};
		
			/* 3-4) Post-increments or post-decrements by one respectively. */
			reverse_iterator operator++(int){
				reverse_iterator tmp(*this);
				--current;
				return (tmp);
			};

			reverse_iterator operator--(int){
				reverse_iterator tmp(*this);
				++current;
				return (tmp);
			};

			/* 5-6) Returns an iterator which is advanced by n or -n positions respectively. */
			reverse_iterator operator+ (difference_type n) const {
				return (reverse_iterator tmp(this->current - n));
			};
			
			reverse_iterator operator- (difference_type n) const {
				return (reverse_iterator tmp(this->current + n));
			};

			/* 7-8) Advances the iterator by n or -n positions respectively. */
			reverse_iterator& operator+=(difference_type n){
				current -= n;
				return (*this);
			};

			reverse_iterator& operator-=(difference_type n){
				current += n;
				return (*this);
			};
			
	};
		/*Non member functions : Operator overloads */ 
		template <class Iter>
			bool operator==(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);
		
		template <class Iter>
			bool operator<(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);

		template <class Iter>
			bool operator!=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);

		template <class Iter>
			bool operator>(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);

		template <class Iter>
			bool operator>=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);

		template <class Iter>
			bool operator<=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);

		template <class Iter>
			typename reverse_iterator<Iter>::difference_type operator-(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs);

		template <class Iter>
			reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& lhs);

}

#endif