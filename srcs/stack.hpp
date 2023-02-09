#include <vector> // TODO : changer quand Vector sera fait !

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

		/* CONSTRUCTORS & DESTRUCTOR */
		explicit stack (){}; // default
		explicit stack (const container_type& ctnr = container_type()){}; // copy
		~stack (){}; // desctructor

		/* MEMBER FUNCTIONS */
		bool				empty() const 				{ return c.empty(); }
		size_type			size() const				{ return c.size(); }
		value_type&			top()						{ return c.back(); }
		const value_type&	top() const					{ return c.back(); }
		void				push(const value_type& x)	{ c.push_back(x); }
		void				pop()						{ c.pop_back(); }
	
	};

	/* RELATIONAL OPERATORS */
		template <class T, class Container>
			bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
		template <class T, class Container>
			bool operator< (const stack<T, Container>& lhs, const stack<T, Container>& rhs);
		template <class T, class Container>
			bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
		template <class T, class Container>
			bool operator> (const stack<T, Container>& lhs, const stack<T, Container>& rhs);
		template <class T, class Container>
			bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
		template <class T, class Container>
			bool operator<=(const stack<T, Container>& lhs,const stack<T, Container>& rhs);

}

//	#########################################
//  #######  RELATIONAL OPERATORS    ########
//  #########################################

template <class T, class Container>
bool ft::operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	(c.lhs == c.rhs) ? true : false;
}


template <class T, class Container>
bool ft::operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	(c.lhs < c.rhs) ? true : false;
}


template <class T, class Container>
bool ft::operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	(c.lhs != c.rhs) ? true : false;
}


template <class T, class Container>
bool ft::operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	(c.lhs > c.rhs) ? true : false;
}


template <class T, class Container>
bool ft::operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	(c.lhs >= c.rhs) ? true : false;
}

template <class T, class Container>
bool ft::operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	(c.lhs <= c.rhs) ? true : false;
}