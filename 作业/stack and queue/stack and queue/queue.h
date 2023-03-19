#pragma once

#include <deque>

namespace my
{
	template <typename T, typename Container = std::deque<T>>
	class queue
	{
	public:
		void push(T val = T())
		{
			c.push_back(val);
		}

		void pop()
		{
			c.pop_front();
		}

		T front()
		{
			return c.front();
		}

		T back()
		{
			return c.back();
		}

		bool empty()
		{
			return c.empty();
		}

		size_t size()
		{
			return c.size();
		}

	private:
		Container c;
	};
}