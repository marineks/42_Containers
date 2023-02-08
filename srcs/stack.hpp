#include <vector>

namespace ft {
  template<class T, class Container = std::vector<T> >
  class stack {
	protected:
			container c;
	
	public:
		/* MEMBER TYPES*/
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container					container_type;

		/* CONSTRUCTORS */
		// Constructor with parameter
		explicit stack (const container_type& ctnr = container_type());
		// Constructor by copy

		bool				empty() const 				{ return c.empty(); }
		size_type			size() const				{ return c.size(); }
		value_type&			top()						{ return c.back(); }
		const value_type&	top() const					{ return c.back(); }
		void				push(const value_type& x)	{ c.push_back(x); }
		void				pop()						{ c.pop_back(); }
	
	
	};
}

template<class T, class Container >
explicit ft::stack::stack (const container_type& ctnr = container_type())
{

}

template <class T, class Container>
bool operator==(const ft::stack::stack<T, Container>& x, const ft::stack::stack<T, Container>& y);

template <class T, class Container>
bool operator< (const ft::stack::stack<T, Container>& x, const ft::stack::stack<T, Container>& y);

template <class T, class Container>
bool operator!=(const ft::stack::stack<T, Container>& x, const ft::stack::stack<T, Container>& y);

template <class T, class Container>
bool operator> (const ft::stack::stack<T, Container>& x, const ft::stack::stack<T, Container>& y);

template <class T, class Container>
bool operator>=(const ft::stack::stack<T, Container>& x, const ft::stack::stack<T, Container>& y);

template <class T, class Container>
bool operator<=(const ft::stack::stack<T, Container>& x, const ft::stack::stack<T, Container>& y);

// namespace std {
// template <class T, class Container = deque<T> > class stack;
// template <class T, class Container>
// bool operator==(const stack<T, Container>& x,
// const stack<T, Container>& y);
// template <class T, class Container>
// bool operator< (const stack<T, Container>& x,
// const stack<T, Container>& y);
// template <class T, class Container>
// bool operator!=(const stack<T, Container>& x,
// const stack<T, Container>& y);
// template <class T, class Container>
// bool operator> (const stack<T, Container>& x,
// const stack<T, Container>& y);
// template <class T, class Container>
// bool operator>=(const stack<T, Container>& x,
// const stack<T, Container>& y);
// template <class T, class Container>
// bool operator<=(const stack<T, Container>& x,
// const stack<T, Container>& y);
// }