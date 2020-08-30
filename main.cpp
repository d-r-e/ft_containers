#include <list>
#include <iterator>
#include "base.hpp"

int main()
{
	{
		ft::list<int> b;
		ft::list<int> c(6);

		std::list<int> d(2);
		std::cout << d.size() << " " << d.max_size() << std::endl;
		d.push_front(5);
		d.push_front(3);
		std::cout << d.size() << " " << d.max_size() << std::endl;
		d.push_front(3);
		std::cout << d.size() << " " << d.max_size() << std::endl;
	}
	{
		ft::list<int> d(2);
		std::cout << d.size() << " " << d.max_size() << std::endl;
		d.push_back(3);
		std::cout << d.size() << " " << d.max_size() << std::endl;
		d.push_front(2);
		std::cout << d.size() << " " << d.max_size() << std::endl;
		ft::list<int> jota = d;
		jota = d;
	}
}