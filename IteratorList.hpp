/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorList.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <darodrig@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:40:06 by darodrig          #+#    #+#             */
/*   Updated: 2020/09/02 17:40:06 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORLIST_HPP
# define ITERATORLIST_HPP
# include "iterator.hpp"
# include "node.hpp"

namespace ft
{
	template <class T, class Category = bidirectional_iterator_tag>
	class IteratorList
	{
	public:
		typedef T				value_type;
		typedef T				&reference;
		typedef T				*pointer;
		typedef Category		category;
		typedef std::ptrdiff_t	difference_type;
	protected:
		Node<T>	*ptr;
	public:
		IteratorList() {}
		~IteratorList() {}
		IteratorList(const IteratorList &rhs) { *this = rhs; }
		IteratorList(Node<T> *ptr) { this->ptr = ptr; }

		IteratorList&	operator=(const IteratorList &rhs)
		{
			this->ptr = rhs.ptr;
			return *this;
		}
		T&				operator*(void) { return *this->ptr->data; }
		T*				operator->(void) { return this->ptr->data; }
		IteratorList&	operator++(void)
		{
			if (this->ptr && this->ptr->next)
				this->ptr = this->ptr->next;
			return (*this);
		}
		IteratorList	operator++(int n)
		{
			IteratorList tmp(*this);
			this->operator++;
			return tmp;
		}
		IteratorList&	operator--(void)
		{
			if (this->ptr && this->ptr->prev)
				this->ptr = this->ptr->prev;
			return (*this);
		}
		IteratorList	operator--(int n)
		{
			IteratorList tmp(*this);
			this->operator--;
			return tmp;
		}
		bool			operator==(IteratorList const &rhs) const
		{
			return (this->ptr == rhs->ptr);
		}
		bool			operator!=(IteratorList const &rhs) const
		{
			return (this->ptr != rhs->ptr);
		}
		Node<T> *getPtr(void) { return this->ptr; }
	};
};

#endif