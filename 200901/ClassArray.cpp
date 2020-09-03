#include <iostream>
#include <exception>

template <typename T, int MAX_COUNT = 100>
class CArray
{
private : 
	T*	m_arr;
	int m_Count;
	int m_MaxCount;

public : 
	CArray()
		: m_MaxCount(MAX_COUNT), m_Count(0)
	{
		m_arr = new T[m_MaxCount];
	}

	~CArray()
	{
		if (m_arr)
		{
			delete[] m_arr;
		}
		m_arr = nullptr;
	}

public : 
	T& operator[](const int _Idx)
	{
		if (_Idx >= m_MaxCount || _Idx < 0)
			throw "잘못된 배열 인덱스 접근";
		return m_arr[_Idx];
	}

	int GetCurCount() const { return m_Count; }
	int GetMaxIdxCount() const { return m_MaxCount; }
};

int main()
{
	CArray<int, 5> arr;

	for (int i = 0; i < arr.GetMaxIdxCount(); i++)
	{
		arr[i] = (i + 1) * 10;
	}

	for (int i = 0; i < arr.GetMaxIdxCount(); i++)
	{
		std::cout << arr[i] << std::endl;
	}
}