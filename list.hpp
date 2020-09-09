/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <darodrig@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:36:44 by darodrig          #+#    #+#             */
/*   Updated: 2020/09/02 17:36:44 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP
# include <iostream>
# include <string>
# include <memory>
# include <limits>
# include <cstddef>
# include "IteratorList.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > 
	class list
	{
		/********************************************************/
		/**** MEMBER TYPES **************************************/
		/********************************************************/
	public:
		typedef size_t	size_type;
		typedef Alloc	allocator_type;
		typedef T		value_type;
		typedef T		&reference;
		typedef T		*pointer;
		typedef const T	&const_reference;
		typedef const T *const_pointer;

		typedef ft::IteratorList<T>					iterator;
		typedef ft::IteratorList<const T>			const_iterator;
		/*
		typedef ft::ReverseIteratorList<T>			reverse_iterator;
		typedef ft::ConstReverseIteratorList<T>		const_reverse_iterator;
		*/
	private:
		size_type		length;
		Node<T>*		head;
		Node<T>*		tail;
		Node<T>*		start;
		Node<T>*		end_;

	public:

		/********************************************************/
		/** CLASS CONSTRUCTORS **********************************/
		/********************************************************/

		explicit list ()
		{
			this->length = 0;
			this->start = new Node<T>();
			this->end_ = new Node<T>();
			start->prev = NULL;
			end_->next = NULL;
			head = start;
			tail = end_;
		}

		/********************************************************/
		/** ITERATORS *******************************************/
		/********************************************************/

		iterator begin(){ return this->head; }
		iterator const cbegin() const { return const_iterator(this->head); }
		iterator end(){ return iterator(this->tail);}
		iterator const cend() const{ return const_iterator(this->tail); }
		
		explicit list (size_type n, const value_type& val = value_type())
		{
			this->length = 0;
			this->insert(this->begin(), n, val);
		}

		/*
		template <class InputIterator>
 		list (InputIterator first, InputIterator last,
        		const allocator_type& alloc = allocator_type());	
		list (const list& x);
		*/

		/********************************************************/
		/** CLASS MODIFIERS *************************************/
		/********************************************************/

		void insert(iterator position, size_type n, const value_type& val)
		{
			Node<T> *cur_node;
			Node<T> *left_node;

			if (this->length == 0 && position != end())
			{
				cur_node = nullptr;
				left_node = nullptr;
			}
			else
			{
				cur_node = position.getPtr();
				if (cur_node == nullptr || begin().getPtr() == nullptr)
					left_node = nullptr;
				else
					left_node = position.getPtr()->prev;
			}
			
			for (unsigned int i = 0; i < n; i++)
			{
				Node<T> *new_node = new Node<T>();
				
				new_node->prev = left_node;
				new_node->next = nullptr;
				new_node->data = val;

				if (left_node)
					left_node->next = new_node;
				else
					this->head = new_node; 
				++this->length;
				left_node = new_node;
			}
			if (cur_node)
			{
				cur_node->prev = left_node;
				left_node->next = cur_node;
			}
			else
				this->tail = left_node;
			
			if (position == end())
				this->tail = left_node;
			this->tail->next = this->end_;
			this->end_->prev = this->tail;
		}
	};
};

#endif