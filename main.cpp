#include <list>
#include <iterator>
#include "list.hpp"
#include <iostream>

int main()
{
	ft::Node<int> a(6);
	ft::Node<int> b;
	ft::Node<int> c = a;
	std::cout << c.data << std::endl;

	ft::list<int> l;
	ft::list<int> m(5, 3);
}