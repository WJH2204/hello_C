#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <assert.h>

using namespace std;

namespace my_ns
{
	class string
	{
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_str = new char[_size + 1];
			_capacity = _size;
			strcpy(_str, str);
		}

		//traditional 
		//string(const string& s)
		//{

		//	_size = s._size;
		//	_capacity = s._capacity;
		//	_str = new char[_capacity+1];
		//	strcpy(_str, s._str);
		//}

		//moderen s1 = s
		string(const string& s)
			:_str(nullptr)
		{

			string tmp(s._str);
			swap(tmp);
		}

		//s1 = s
		string& operator=(string s)
		{
			//assert(*this == s);

			swap(s);

			return *this;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		//string& operator=(const string& s)
		//{
		//	char* ch = new char[s._size];
		//	strcpy(ch, s._str);
		//	_size = s._size;
		//	_capacity = s._capacity;
		//	delete[] _str;
		//	_str = ch;
		//	return *this;
		//}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		// iterator
		typedef char* iterator;
		iterator begin() const
		{
			return _str;
		}
		iterator end() const
		{
			return _str + _size;
		}

		//access
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			
			return _str[pos];
		}

		char operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		size_t find(const char c, size_t pos = 0) const
		{
			assert(pos < _size);
			while (pos < _size)
			{
				if (_str[pos] == c)
					return pos;
				++pos;
			}

			return npos;
		}

		size_t find(const char* str, size_t pos = 0) const
		{
			assert(pos < _size);
			char* p = strstr(_str+pos, str);
			if (p == nullptr)
				return npos;
			return p - _str;
		}

		const char* c_str() const
		{
			return _str;
		}

		//modify
		void push_back(char c)
		{
			if (_size == _capacity)
			{
				size_t n = _capacity * 2 > 0 ? _capacity * 2 : 4;
				reserve(n);
			}

			_str[_size++] = c;
			_str[_size] = '\0';
		}

		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void append(const char* str)
		{
			size_t n = strlen(str);
			if (_size + n > _capacity)
			{
				reserve(_size + n);
			}

			strcpy(_str + _size, str);
			_size += n;
		}

		string& insert(size_t pos, char ch = '\0')
		{
			assert(pos <= _size);

			if (_size == _capacity)
			{
				size_t n = _capacity * 2 > 0 ? _capacity * 2 : 4;
				reserve(n);
			}

			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);

			size_t len = strlen(str);

			size_t n = _size + len;

			if (n > _capacity)
			{
				reserve(n);
			}

			size_t end = _size + len;
			while (end > pos + len - 1)
			{
				_str[end] = _str[end - len];
				--end;
			}
			
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}

		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}

			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}


		//capacity
		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		void resize(size_t n, char c = '\0')
		{
			if (n <= _size)
			{
				_size = n;
				_str[n] = '\0';
			}

			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				size_t count = n - _size;
				while (count--)
				{
					push_back(c);
				}
				_str[n] = '\0';
				_size = n;

			}
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* newstr = new char[n + 1];
				_capacity = n;
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
			}

			else
			{
				;
			}
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		bool empty() const
		{
			return !_size;
		}


		//relational operator
		bool operator<(const string& s)
		{
			for (int i = 0; i < _size && i < s._size; ++i)
			{
				if (_str[i] >= s._str[i])
					return false;
			}

			return true;
		}

		bool operator<=(const string& s)
		{
			for (int i = 0; i < _size && i < s._size; ++i)
			{
				if (_str[i] > s._str[i])
					return false;
			}

			return true;
		}

		bool operator>(const string& s)
		{
			return !(*this <= s);
		}

		bool operator>=(const string& s)
		{
			return !(*this < s);
		}

		bool operator==(const string& s)
		{
			if (_size != s._size)
				return false;
			for (int i = 0; i < _size; ++i)
			{
				if (_str[i] != s._str[i])
					return false;
			}

			return true;
		}

		bool operator!=(const string& s)
		{
			return !(*this == s);
		}

	private:
		char* _str;
		size_t _capacity;
		size_t _size;
		const static size_t npos = -1;
	};

	ostream& operator<<(ostream& out, const string& s)
	{
		for (int i = 0; i < s.size(); ++i)
		{
			out << s[i];
		}

		return out;
	}


	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char c = in.get();
		char temporary_container[128] = { '\0' };
		int i = 0;
		while (c != ' ' && c != '\n')
		{
			if (i == 127)
			{
				s += temporary_container;
				i = 0;
			}

			temporary_container[i++] = c;
			c = in.get();
		}

		if (i > 0)
		{
			temporary_container[i] = '\0';
			s += temporary_container;
		}

		return in;
	}

	void test()
	{
		string s1("qwe");
		string s2("awe");
		
		cout << s1.empty() << endl;
	}
}


