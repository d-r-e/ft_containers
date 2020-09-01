#ifndef LIST_HPP
# define LIST_HPP
# include <iostream>
# include <string>
# include <memory>
# include <limits>
namespace ft
{
	template<typename T>
	struct Node
	{
		T		data;
		Node<T>	*next;
		Node<T>	*prev;

		Node<T>(): data(), next(NULL), prev(NULL) {}
		Node<T>(T data): data(data), next(NULL), prev(NULL) {}
		Node<T>(const Node<T> &rhs): data(rhs.data), next(rhs.next), prev(rhs.prev) {}
		Node<T> & operator=(const Node<T> &rhs) { *this = rhs; }
		~Node<T>() {}
	};

	template < class T, class Alloc = std::allocator<T> > 
	class list
	{
	public:
		typedef size_t	size_type;
		typedef Alloc	allocator_type;
		typedef T		value_type;
		typedef T		&reference;
		typedef T		*pointer;
		typedef const T	&const_reference;
		typedef const T *const_pointer;
		/*
		typedef ft::IteratorList<T>								iterator;
		typedef ft::ConstIteratorList<T>						const_iterator;
		typedef ft::ReverseIteratorList<T>						reverse_iterator;
		typedef ft::ConstReverseIteratorList<T>					const_reverse_iterator;
		*/
	private:
		size_type		_size;
		allocator_type	_alloc;
		Node<T>*		_head;
		Node<T>*		_tail;
		Node<T>*		_start;
		Node<T>*		_end;
		
		size_t _max_size = 768614336404564650UL;

	public:
		explicit list (const allocator_type& alloc = allocator_type())
		{
			this->_alloc = alloc;
			this->_size = 0;
			this->_start = new Node<T>();
			this->_end = new Node<T>();
			_start->prev = NULL;
			_end->next = NULL;
			_head = _start;
			_tail = _end;
		}
	/*	explicit list (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type());
		template <class InputIterator>
 		list (InputIterator first, InputIterator last,
        		const allocator_type& alloc = allocator_type());	
		list (const list& x);
		*/
	};

};

#endif