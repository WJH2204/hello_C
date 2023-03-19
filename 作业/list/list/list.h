#pragma once
#include <iostream>
#include "reverse_iterator.h"

namespace my
{
	

	template <typename T>
	class listnode
	{
	public:
		typedef listnode<T> _node;
		typedef listnode<T>* _node_ptr;

		listnode(const T& val = T())
			:_prev_ptr(nullptr)
			, _next_ptr(nullptr)
			, _val(val)
		{
		}

		// 成员变量
		_node_ptr _prev_ptr;
		_node_ptr _next_ptr;
		T _val;
	};


	template<typename T, typename Ref, typename Ptr>
	class _list_iterator
	{
	public:

		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;
		typedef listnode<T>* _node_ptr;

		_list_iterator(const _node_ptr& ptr = nullptr)
			:_it(ptr)
		{
			;
		}

		Ref operator*()
		{
			return _it->_val;
		}

		Ptr operator->()
		{
			return &_it->_val;
		}

		void operator++()
		{
			_it = _it->_next_ptr;
		}

		_list_iterator operator++(int)
		{
			_list_iterator tmp = *this;
			_it = _it->_next_ptr;

			return tmp;
		}

		_list_iterator operator--(int)
		{
			_list_iterator tmp = *this;
			_it = _it->_prev_ptr;
			return tmp;
		}

		_list_iterator operator--()
		{
			_it = _it->_prev_ptr;
			return *this;
		}

		//bool operator!=(iterator it)
		//{
		//	return (_it != it._it);
		//}

		bool operator!=(const _list_iterator& it) const
		{
			return (_it != it._it);
		}

		bool operator==(const _list_iterator& it)
		{
			return !(*this != it);
		}



		_node_ptr _it;
	};
	
	template <typename T>
	class list
	{
	public:
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;
		typedef my::reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef my::reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;
		typedef listnode<T> _node;
		typedef listnode<T>* _node_ptr;

		void empty_initialize(const T& val = T())
		{
			_head = new _node(val);
			_head->_prev_ptr = _head;
			_head->_next_ptr = _head;
		}

		list(const T& val = T())
		{
			empty_initialize(val);
		}

		template<typename InputIterator>
		list(InputIterator first, InputIterator last)
		{
			empty_initialize();

			while (first != last)
			{
				push_back(*first);
				++first;
			}

		}

		//list(const list<T>& ls)
		//{
		//	empty_initialize();

		//	for (auto& val : ls)
		//	{
		//		push_back(val);
		//	}
		//}

		list(const list<T>& ls)
		{
			empty_initialize();
			list<T> tmp(ls.begin(), ls.end());

			swap(tmp);
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}


		iterator begin()
		{
			return iterator(_head->_next_ptr);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next_ptr);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
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

		void push_back(const T& val = T())
		{
			insert(end(), val);
			
			//_node_ptr tmp = new _node(val);
			//_node_ptr tail = _head->_prev_ptr;
			//tail->_next_ptr = tmp;
			//tmp->_prev_ptr = tail;
			//_head->_prev_ptr = tmp;
			//tmp->_next_ptr = _head;
		}

		void push_front(const T& val = T())
		{
			insert(begin(), val);
		}

		void pop_front()
		{
			erase(begin());
		}

		void pop_back()
		{
			
			erase(--end());
		}

		iterator insert(iterator pos, const T& val = T())
		{
			_node_ptr _new_node = new _node(val);

			// pre new next

			_node_ptr pre = (pos._it)->_prev_ptr;
			_node_ptr next = pos._it;

			pre->_next_ptr = _new_node;
			_new_node->_prev_ptr = pre;
			_new_node->_next_ptr = next;
			next->_prev_ptr = _new_node;

			++_size;

			return iterator(_new_node);
		}

		iterator erase(iterator pos)
		{
			_node_ptr pre = (pos._it)->_prev_ptr;
			_node_ptr next = (pos._it)->_next_ptr;

			pre->_next_ptr = next;
			next->_prev_ptr = pre;

			delete (pos._it);

			--_size;
			return next;
		}

		void clear()
		{
			iterator it = begin();

			while (it != end())
			{
				it = erase(it);
			}
		}

		//list<T>& operator=(const list<T>& ls)
		//{
		//	clear();

		//	for (auto& val : ls)
		//	{
		//		push_back(val);
		//	}

		//	return *this;
		//}

		list<T>& operator=(list<T> ls)
		{
			swap(ls);

			return *this;
		}

		size_t size()
		{
			return _size;
		}

		bool empty()
		{
			return (_size == 0);
		}


	private:
		_node_ptr _head;
		size_t _size = 0;

	};
}
