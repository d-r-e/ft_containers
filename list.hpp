#include <iostream>
#include <string>

namespace ft
{
	template<typename T>
	class list
	{
	private:
		size_t _size;
		size_t _max_size = 768614336404564650;
		T	*_elem;
	public:
		list(): _size(0), _elem(new T[0]) {}
		list(unsigned int n): _size(n), _elem(new T[n]) {}
		list(const list<T> &rhs) { *this = rhs; }
		list<T> & operator=(const list<T> &rhs){
			if (this == &rhs)
				return (*this);
			this->_size = rhs.size();
			this->_elem = new T[_size];
			for (int i = 0; i < _size; ++i)
				this->_elem[i] = rhs._elem[i];
			this->_elem = rhs._elem;
			return *this;
		}
		~list() { delete [] this->_elem; }

		bool	empty(void) const { return (this->_size > 0); }
		size_t	size(void) const { return (this->_size); }
		size_t	max_size(void) const { return this->_max_size; }

		void push_back(const T& val){
			if (_size == _max_size)
				throw std::exception();
			T *tmp = new T[_size + 1];
			for (int i = 0; i < _size; ++i)
				tmp[i] = _elem[i];
			tmp[_size] = val;
			_size++;
			delete [] _elem;
			_elem = tmp;
		}

		void push_front(const T& val){
			if (_size == _max_size)
				throw std::exception();
			T *tmp = new T[_size + 1];
			tmp[0] = val;
			for (int i = 1; i < _size + 1; ++i)
				tmp[i] = _elem[i];
			tmp[_size] = val;
			_size++;
			delete [] _elem;
			_elem = tmp;
		}
	};

};