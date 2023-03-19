#pragma once
#include <vector>

using namespace std;

namespace my
{
	template <class T, class Container = vector<T>, class Compare = my::less<T>>
	class priority_queue
	{
	public:
		priority_queue() {}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_con(first, last)
		{
			for (int i = (size() - 1 - 1) / 2; i >= 0; --i)
			{
				adjust_down(i);
			}
		}

		void push(const T& val = T())
		{
			_con.push_back(val);
			adjust_up(size() - 1);
		}

		void pop()
		{
			std::swap(_con[0], _con[size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		const T& top()
		{
			return _con[0];
		}

		bool empty()
		{
			return _con.empty();
		}

		size_t size()
		{
			return _con.size();
		}

	private:
		Container _con;

		void adjust_up(size_t child)
		{
			Compare com;

			size_t parent = (child - 1) / 2;

			while (child > 0)
			{
				if (com(_con[child], _con[parent]))
				{
					std::swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void adjust_down(size_t parent)
		{
			Compare com;

			size_t child = parent * 2 + 1;

			while (child < size())
			{
				if (child + 1 < size() && com(_con[child + 1], _con[child]))
				{
					++child;
				}

				if(com(_con[child], _con[parent]))
				{
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
	};

	template <class T>
	class less
	{
	public:
		bool operator()(const T& v1, const T& v2)
		{
			return v1 > v2;
		}
	};

	template <class T>
	class greater
	{
	public:
		bool operator()(const T& v1, const T& v2)
		{
			return v1 < v2;
		}
	};
}
