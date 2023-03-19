#pragma once

#include <iostream>
#include <assert.h>
#include "reverse_iterator.h"

using namespace std;

namespace my {
	template <typename T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef my::reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef my::reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;


		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());;
		}

		const_reverse_iterator crbegin() const
		{
			return const_reverse_iterator(end());
		}

		const_reverse_iterator crend() const
		{
			return const_reverse_iterator(begin());;
		}

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			;
		}

		vector(size_t n, const T& val = T())
		{
			while (n--)
			{
				push_back(val);
			}
		}

		vector(int n, const T& val = T())
		{
			while (n--)
			{
				push_back(val);
			}
		}

		vector(const vector<T>& v)
		{
			vector<T> vv(v.begin(), v.end());
			swap(vv);
		}

		vector& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		template<typename InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			
			while (first != last)
			{
				push_back(*first++);
			}
		}

		~vector()
		{
			delete[] _start;
			_start = nullptr;
			_finish = nullptr;
			_endOfStorage = nullptr;
		}

		void push_back(const T& x) {
			if (_finish == _endOfStorage)
			{
				size_t newcapcity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapcity);
			}

			*_finish = x;
			++_finish;
		}

		void reserve(size_t n) {
			size_t old_capacity = capacity();
			size_t old_size = size();
			if (n > old_capacity)
			{
				iterator tmp = new T[n];

				if (_start) //
				{
					for (size_t i = 0; i < old_size; ++i)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				
				_start = tmp;
				_finish = _start + old_size;
				_endOfStorage = _start + n; // n

			}
		}

		size_t size() const {
			return (_finish - _start);
		}

		size_t capacity() const {
			return (_endOfStorage - _start);
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

		bool empty() const
		{
			return (_start == _finish);
		}

		void resize(size_t n, T val = T())
		{
			if (n > capacity())
			{
				reserve(n);
			}
			if (n > size())
			{
				while (size() != n)
					push_back(val);
			}
			if (n < size())
				_finish = _start + n;
		}

		void pop_back()
		{
			assert(_finish != _start);
			--_finish;
		}

		iterator insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			if (_finish == _endOfStorage)
			{
				size_t len = pos - _start;
				int newcapcity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapcity);
				pos = _start + len; //
			}
			iterator end = _finish;

			while (end > pos)
			{
				*end = *(end - 1);
				--end;
			}
			*pos = val;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			iterator my_start = pos;
			while (my_start < _finish - 1)
			{
				*my_start = *(my_start + 1);
				++my_start;
			}
			--_finish;
			return pos;
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endOfStorage, v._endOfStorage);
		}

		void clear()
		{
			_finish = _start;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endOfStorage;

	};


}
