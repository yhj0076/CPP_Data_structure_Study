#include <iostream>
#include <list>

int main()
{
	std::list<int> intList;

	intList.push_back(10);
	intList.push_back(20);
	intList.push_back(30);
	intList.push_back(40);
	intList.push_back(50);

	intList.push_front(50);
	intList.push_front(40);
	intList.push_front(30);
	intList.push_front(20);
	intList.push_front(10);

	// 반복자(iterator)를 사용해서 노드에 접근한다.
	std::list<int>::iterator iter;

	for (std::list<int>::iterator i = intList.begin(); i != intList.end(); i++)
	{
		std::cout << *i << std::endl;
	}

	for (auto i = intList.begin(); i != intList.end(); i++)
	{
		std::cout << *i << std::endl;
	}

	for (auto i : intList)
	{
		std::cout << i << std::endl;
	}

	return 0;
}