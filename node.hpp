/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <darodrig@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:37:28 by darodrig          #+#    #+#             */
/*   Updated: 2020/09/02 17:37:28 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
	template<typename T>
	struct Node
	{
		T		*data;
		Node<T>	*next;
		Node<T>	*prev;

		/*
		Node<T>(): data(), next(NULL), prev(NULL) {}
		Node<T>(T data): data(data), next(NULL), prev(NULL) {}
		Node<T>(const Node<T> &rhs): data(rhs.data), next(rhs.next), prev(rhs.prev) {}
		Node<T> & operator=(const Node<T> &rhs) { *this = rhs; }
		~Node<T>() {}
		*/
	};

};