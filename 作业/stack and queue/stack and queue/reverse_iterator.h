#pragma once

namespace my
{
	template <class Iterator, class Ref, class Ptr>
	class reverse_iterator
	{
	public:

		reverse_iterator(Iterator it)
			:_it(it)
		{

		}

		reverse_iterator& operator++()
		{
			--_it;
			return *this;
		}

		reverse_iterator& operator--()
		{
			++_it;
			return *this;
		}

		bool operator!=(const reverse_iterator& it) const
		{
			return _it != it._it;
		}

		Ref operator*() 
		{
			Iterator tmp = _it;
			return *(--tmp);
		}

		Ptr operator->()
		{
			return &(operator*());
		}

	private:
		Iterator _it;
	};
}
