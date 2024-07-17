#include <iostream>
#include <algorithm>
#include <cassert>

class IntArray
{
private:
    int* m_array { nullptr };
	int m_length { 0 };

public:
    explicit IntArray(int length = 0):
		m_length { length }
	{
		assert(length > 0 && "IntArray length should be a positive integer");
	
		m_array = new int[m_length] {};
	}

	IntArray(const IntArray& array)
		: m_length { array.m_length }
	{
		m_array = new int[m_length];

		for (int i{0}; i < m_length; ++i)
			m_array[i] = array.m_array[i];
	}

	~IntArray()
	{
		delete[] m_array;
	}

    int& operator[](int index)
	{
		assert(index >= 0);
		assert(index < m_length);
		return m_array[index];
	}

	friend std::ostream& operator<<(std::ostream& out, IntArray array)
	{
		for (int i{0}; i < array.m_length; ++i)
		{
			out << array.m_array[i] << ' ';
		}
		return out;
	}

	IntArray& operator=(const IntArray& source)
	{
		if (this == &source)
			return *this;
		
		delete[] m_array;

		m_length = source.m_length;

		m_array = new int[m_length];

		for (int i{0}; i < m_length; ++i)
			m_array[i] = source.m_array[i];

		return *this;
	}
};

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}