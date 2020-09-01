#include <iostream>

// 템플릿화
// 다양한 자료형들을 대응할 수 있는 클래스 및 함수를 구현하는 것으로 
// 이러한 자료형들은 컴파일할 때 결정된다. (즉 문법 검사를 하면서 그 시간동안 다 매칭이 되는 방식의 프로그래밍)
template <typename T>
class CArray
{
private : 
	T* m_Arr;			// T타입의 배열(즉 데이터 저장소)
	int m_Count;		// 데이터가 몇 개 들어왔나
	int m_MaxCount;		// 데이터가 총 몇개까지 들어올 수 있나!

public : 
	void Add(T _elem)
	{

	}

	T Delete()
	{

	}

	int GetCount() const
	{
		return m_Count;
	}

	int GetMaxCount() const
	{
		return m_MaxCount;
	}
};

int main()
{

	return 0;
}